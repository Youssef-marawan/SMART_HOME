/*
 *
 *  Created on: 10/08/2024
 *  Author	  : YOUSSEF MARAWAN
 *  Project	  : SMART HOME
 *
 */


#include "Header_Files.h"



int main(){

	//DIO Init.
	DIO_Set_Dir();

	//Timer 0 Init.
	TIMER0_init();

	//Preload for Timer 0 (1 sec)
	TIMER0_set_preload(PRELOAD_VALUE);

	//set call back function for timer 0
	TIMER0_SetCallBack(check_function,SECOND);

	//EXT. Interrupt
	EXT_INT_0_Init();

	EXT_INT_0_CallBack(reset);

	//ADC Init
	ADC_Init();

	//LCD Init
	LCD_voidInit();

	//Global Interrupt
	GLOBAL_INTERRUPT_Init();

	//UART Init.
	UART_Init();

	//KEYPAD Init.
	KeyPad_Init();

	//Master I2C Init.
	TWI_Master_Init(TWI_MASTER_ADDRESS);

	//SERVO Init. and TIMER 1
	SERVO_Init();


	DIO_vSetPinHigh(B7);

	//read address 10 from EEPROM
	//to check it is the first time or not
	EEPROM_Read_Data(TEST_ADDRESS,test_word,ONE_CHAR);

	//if we setup the program for first time
	if(test_word[0] != PROGRAM_WORKED){

		//First Screen
		LCD_voidSetCursor(0,2);
		LCD_voidSendString("Welcome Home");
		_delay_ms(1500);
		LCD_CLEAR();


		//Second Screen
		LCD_voidSetCursor(0,0);
		LCD_voidSendString("1-Setup Program");
		while(1){
			if(KeyPad_GetKey() == 1){
				break;
			}
		}
		LCD_CLEAR();


		//Screen to take Username
		LCD_voidSetCursor(0,0);
		LCD_voidSendString("UserName :");
		//varible to store username
		u8 username[7];
		//variable to use as counter
		u8 i;
		for(i=11;i<16;i++){
			LCD_voidSetCursor(0,i);
			//using TTL
			u8 value = UART_ReceiveData();
			//end of username
			if(value == ENTER ){break;}
			//print on screen
			LCD_voidSendChar(value);
			//save in varible username
			username[i-11] = value;
		}
		//end of string
		username[i-11]='\0';


		//Same Screen to take Password
		LCD_voidSetCursor(1,0);
		LCD_voidSendString("Password :");
		//varible to store password
		u8 password[3];
		for(i=11;i<14;i++){
			LCD_voidSetCursor(1,i);
			//using TTL
			u8 value = UART_ReceiveData();
			//print on screen
			LCD_voidSendChar(value);
			//disappear password
			_delay_ms(500);
			LCD_voidSetCursor(1,i);
			LCD_voidSendChar('*');
			//store in variable password
			password[i-11] = value;
		}
		//end of string
		password[i-11]='\0';

		//screen LOADING to store data in EEPROM
		LCD_CLEAR();
		LCD_voidSendString("LOADING...");

		//store username to EEPROM
		for(i=0;i<3;i++){
			EEPROM_Send_Data(username[i],i);
		}

		//store password to EEPROM
		u8 j=0;
		for(i=3;i<6;i++){
			EEPROM_Send_Data(password[j],i);
			j++;
		}

		//read user data from EEPROM and store it in varible userdata
		EEPROM_Read_Data(DATA_ADDRESS,user_data,SIX_CHAR);

		//store word in EEPROM to make the program setuped
		EEPROM_Send_Data(PROGRAM_WORKED,TEST_ADDRESS);


		_delay_ms(1000);


	}
	else{
		//if this is does not the first time
		//read the data of user from EEPROM
		EEPROM_Read_Data(DATA_ADDRESS,user_data,6);
	}





	//Screen after SetUp
	LCD_CLEAR();
	LCD_voidSetCursor(0,2);
	LCD_voidSendString("Welcome  ");
	u8 i;
	for(i=0;i<3;i++){
		//print username on screen
		LCD_voidSendChar(user_data[i]);
	}


	//same screen to check password
	LCD_voidSetCursor(1,0);
	LCD_voidSendString("Password : ");
	//varible to check the number of test
	u8 error_counter = 0;
	while(error_counter < 3){
		//varible to take password from user
		u8 password_test[3];
		//variable to count the password digits (3)
		u8 pass_counter = 0;
		i=11;
		while(pass_counter < 3){
			while(1){
				s8 value = KeyPad_GetKey();
				if(value != -1){
					password_test[pass_counter] = value;
					LCD_voidSendNumber(value);
					//disappear password
					_delay_ms(500);
					LCD_voidSetCursor(1,i);
					LCD_voidSendChar('*');
					i++;
					pass_counter++;
					break;
				}
			}
		}
		//check the password
		if(password_test[0] == (user_data[3] - '0') && password_test[1] == (user_data[4] - '0') && password_test[2] == (user_data[5] - '0') ){
			break;
		}
		else{
			LCD_CLEAR();
			LCD_voidSendString("WRONG !");
			//turn on red led
			LED_vSetLedOn(D6);
			//turn on buzzer
			BUZZ_vPlay(D7);
			_delay_ms(500);
			//turn off red led
			LED_vSetLedOff(D6);
			LCD_CLEAR();
			LCD_voidSetCursor(1,0);
			LCD_voidSendString("Password : ");
			error_counter++;
		}
	}


	//if the 3 tests is wrong the systen will hold
	if(error_counter > 2){
		LCD_CLEAR();
		LCD_voidSendString("System Stopped...");
		while(1){
			BUZZ_vPlay(D7);
			LED_vSetLedToggle(D6);
		}
	}
	//if the password is true
	else{
		LCD_CLEAR();
		LCD_voidSetCursor(0,2);
		LCD_voidSendString("Welcome Back");
		LCD_voidSetCursor(1,1);
		LCD_voidSendString("The Door Opened");
		//make servo rotate to 90 degree
		SERVO_Rotate(ANGLE_90);
		//store the state of door
		door = OPENED;
		_delay_ms(1200);

	}


	//screen after entering home close door and open lights
	LCD_CLEAR();
	LCD_voidSendString("1-Close Door");
	while(KeyPad_GetKey() != 1);
	//make servo rotate to 0 degree
	SERVO_Rotate(ANGLE_0);
	//store the state of door
	door = CLOSED;
	//turn on the inside light
	LED_vSetLedOn(A3);
	//store the state of inside light
	light_in = ON;


	//superloop
	while(1){

		//main screen
		LCD_CLEAR();
		LCD_voidSendString("1-lights  2-Door");
		LCD_voidSetCursor(1,0);
		LCD_voidSendString("3-Temp    4-More");

		//varible to get the value of button has pressed
		s8 main_key = KeyPad_GetKey();


		//get choice from the main screen(1,2,3,4)
		while(main_key == UNPRESSED || main_key == 0 || main_key > 4 ){ main_key = KeyPad_GetKey(); }

		switch(main_key){
			//Lights
			case 1:
				//light screen
				LCD_CLEAR();
				LCD_voidSendString("1-In       2-Out");
				LCD_voidSetCursor(1,0);
				LCD_voidSendString("3-back");


				//varible to get the value of button has pressed
				s8 light_key = KeyPad_GetKey();
				//varible to get the value of button has pressed in side this screen
				s8 value_in;

				//get choice from the light screen(1,2,3)
				while(light_key == UNPRESSED || light_key == 0 || light_key > 3 ){ light_key = KeyPad_GetKey(); }

				switch(light_key){
					//inside light screen
					case 1:

						do{
							LCD_CLEAR();
							LCD_voidSendString("light In is :");
							//check the inside light state
							if(light_in == ON){
								LCD_voidSendString("ON");
								LCD_voidSetCursor(1,0);
								LCD_voidSendString("1-TurnOff 2-Back");
							}
							else{
								LCD_voidSendString("OFF");
								LCD_voidSetCursor(1,0);
								LCD_voidSendString("1-TurnOn  2-Back");
							}
							value_in = KeyPad_GetKey();

							while(value_in == UNPRESSED){value_in = KeyPad_GetKey();}

							if(value_in == 1 ){
								//toggle the state of inside light
								light_in = light_in ^ 1;
								LED_vSetLedToggle(A3);
							}
						}while(value_in != 2);
						break;


					case 2:
						//light out door
						do{
							LCD_CLEAR();
							LCD_voidSendString("Out is : ");
							//check the state of outside lights
							if(light_out == MORNING){
								LCD_voidSendString("Morning");
							}
							else{
								LCD_voidSendString("Night");
							}
							LCD_voidSetCursor(1,0);
							LCD_voidSendString("1-back");
							value_in = KeyPad_GetKey();
							//this varible use to count time renewal LDR value
							u16 time_out = 0;

							while(value_in == UNPRESSED && time_out < 1500){
								value_in = KeyPad_GetKey();
								time_out++;
							}
							time_out = 0;

						}while(value_in != 1);
						break;
				}
				break;


			case 2:
				//door screen
				do{
					LCD_CLEAR();
					LCD_voidSendString("door is ");
					//check the state of the door
					if(door == OPENED){
						LCD_voidSendString("open");
						LCD_voidSetCursor(1,0);
						LCD_voidSendString("1-close   2-back");
						value_in = KeyPad_GetKey();

						while(value_in == UNPRESSED){value_in = KeyPad_GetKey();}

						if(value_in == 1){
							//change state of door
							door = CLOSED;
							SERVO_Rotate(ANGLE_0);
						}
					}
					else if(door == CLOSED){
						LCD_voidSendString("close");
						LCD_voidSetCursor(1,0);
						LCD_voidSendString("1-open   2-back");
						value_in = KeyPad_GetKey();

						while(value_in == -1){value_in = KeyPad_GetKey();}

						if(value_in == 1){
							//change state of door
							door = OPENED;
							SERVO_Rotate(ANGLE_90);
						}
					}
				}while(value_in != 2);
				break;


			case 3:
				//temp screen
				do{
					LCD_CLEAR();
					LCD_voidSendString("Temp is ");
					LCD_voidSendNumber(temp);
					LCD_voidSendString(" C");
					LCD_voidSetCursor(1,0);
					LCD_voidSendString("1-Back");
					value_in = KeyPad_GetKey();
					//this varible use to count time renewal TEMP. value
					u16 time_out = 0;

					while(value_in == UNPRESSED && time_out < 1500){
						value_in = KeyPad_GetKey();
						time_out++;
					}
					time_out = 0;

				}while(value_in != 1);

				break;

			case 4:
				//More screen
				do{
					LCD_CLEAR();
					LCD_voidSendString("1-Window 2-Sleep");
					LCD_voidSetCursor(1,0);
					LCD_voidSendString("3-Fan    4-Back ");

					//varible to get the value of button has pressed
					s8 main_key = KeyPad_GetKey();


					//get choice from the main screen(1,2,3,4)
					while(main_key == UNPRESSED || main_key == 0 || main_key > 4 ){ main_key = KeyPad_GetKey(); }

					switch(main_key){
						case 1:
							//Window Screen
							do{
								LCD_CLEAR();
								LCD_voidSendString("Window is ");
								//check the state of the door
								if(window == OPENED){
									LCD_voidSendString("open");
									LCD_voidSetCursor(1,0);
									LCD_voidSendString("1-close   2-back");
									value_in = KeyPad_GetKey();

									while(value_in == UNPRESSED){value_in = KeyPad_GetKey();}

									if(value_in == 1){
										//change state of window
										window = CLOSED;
										STEPPER_CW(360);
										STEPPER_Stop();
									}
								}
								else if(window == CLOSED){
									LCD_voidSendString("close");
									LCD_voidSetCursor(1,0);
									LCD_voidSendString("1-open   2-back");
									value_in = KeyPad_GetKey();

									while(value_in == -1){value_in = KeyPad_GetKey();}

									if(value_in == 1){
										//change state of window
										window = OPENED;
										STEPPER_ACW(360);
										STEPPER_Stop();
									}
								}
							}while(value_in != 2);

							break;
						case 2:
							do{
								//Sleep
								if(door == OPENED){
									//change state of door
									door = CLOSED;
									SERVO_Rotate(ANGLE_0);
								}
								if(window == OPENED){
									//change state of window
									window = CLOSED;
									STEPPER_CW(360);
									STEPPER_Stop();
								}
								if(light_in == ON){
									//toggle the state of inside light
									light_in = light_in ^ 1;
									LED_vSetLedToggle(A3);
								}
								LCD_voidSendCommand(0X08);
								DIO_vSetPinLOW(B7);
								sleep = UART_ReceiveData();

							}while(sleep != WAKEUP);
							LCD_voidSendCommand(0X0C);
							DIO_vSetPinHigh(B7);
							break;
						case 3:
							//Fan Screen
							do{
							//check fan state
							if(fan == OFF){
								LCD_CLEAR();
								LCD_voidSendString("Fan is ");
								LCD_voidSendString("off");
								LCD_voidSetCursor(1,0);
								LCD_voidSendString("1-R  2-L  3-back");
								value_in = KeyPad_GetKey();

								while(value_in == UNPRESSED){value_in = KeyPad_GetKey();}
								switch(value_in){
									case 1:
										fan = RIGHT;
										DC_MOTOR_Move(DC_MOTOR_CLK);
										break;
									case 2:
										fan = LEFT;
										DC_MOTOR_Move(DC_MOTOR_ANTI_CLK);
										LED_vSetLedOn(D4);
										break;
									case 3:
										value_in = 3;
										break;

								}
							}
							else if(fan == RIGHT){
								LCD_CLEAR();
								LCD_voidSendString("Fan is ");
								LCD_voidSendString("right");
								LCD_voidSetCursor(1,0);
								LCD_voidSendString("1-off 2-L 3-back");
								value_in = KeyPad_GetKey();

								while(value_in == UNPRESSED){value_in = KeyPad_GetKey();}

								switch(value_in){
									case 1:
										fan = OFF;
										DC_MOTOR_Move(DC_MOTOR_STOP);
										break;
									case 2:
										fan = LEFT;
										DC_MOTOR_Move(DC_MOTOR_ANTI_CLK);
										break;
									case 3:
										value_in = 3;
										break;

								}
							}
							else{
								LCD_CLEAR();
								LCD_voidSendString("Fan is ");
								LCD_voidSendString("left");
								LCD_voidSetCursor(1,0);
								LCD_voidSendString("1-off 2-R 3-back");
								value_in = KeyPad_GetKey();

								while(value_in == UNPRESSED){value_in = KeyPad_GetKey();}

								switch(value_in){
									case 1:
										fan = OFF;
										DC_MOTOR_Move(DC_MOTOR_STOP);
										break;
									case 2:
										fan = RIGHT;
										DC_MOTOR_Move(DC_MOTOR_CLK);
										break;
									case 3:
										value_in = 3;
										break;

								}
							}
							}while(value_in != 3);
							break;

					}

				}while(main_key != 4);
				break;

		}

	}

}





