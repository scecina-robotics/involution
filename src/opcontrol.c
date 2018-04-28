/** @file opcontrol.c
 * @brief File for operator control code
 *
 * This file should contain the user operatorControl() function and any functions related to it.
 *
 * Any copyright is dedicated to the Public Domain.
 * http://creativecommons.org/publicdomain/zero/1.0/
 *
 * PROS contains FreeRTOS (http://www.freertos.org) whose source code may be
 * obtained from http://sourceforge.net/projects/freertos/files/ or on request.
 */

#include "main.h"
#include "wheels.h"
#include "trough.h"
#include "scoop.h"
#include "autocode.h"
/*
 * Runs the user operator control code. This function will be started in its own task with the
 * default priority and stack size whenever the robot is enabled via the Field Management System
 * or the VEX Competition Switch in the operator control mode. If the robot is disabled or
 * communications is lost, the operator control task will be stopped by the kernel. Re-enabling
 * the robot will restart the task, not resume it from where it left off.
 *
 * If no VEX Competition Switch or Field Management system is plugged in, the VEX Cortex will
 * run the operator control task. Be warned that this will also occur if the VEX Cortex is
 * tethered directly to a computer via the USB A to A cable without any VEX Joystick attached.
 *
 * Code running in this task can take almost any action, as the VEX Joystick is available and
 * the scheduler is operational. However, proper use of delay() or taskDelayUntil() is highly
 * recommended to give other tasks (including system tasks such as updating LCDs) time to run.
 *
 * This task should never exit; it should end with some kind of infinite loop, even if empty.
 */

int LeftStickVert;
int RightStickVert;
bool TroughUp;
bool TroughDown;
bool ScoopArmUp;
bool ScoopArmDown;
bool ScoopGateUpLeft;
bool ScoopGateDownLeft;
bool ScoopGateUpRight;
bool ScoopGateDownRight;
//Partner Contoller
bool PartTroughUp;
bool PartTroughDown;
bool PartScoopArmUp;
bool PartScoopArmDown;
bool PartScoopGateUpLeft;
bool PartScoopGateDownLeft;
bool PartScoopGateDownRight;
bool PartScoopGateUpRight;

bool AutoCodeExecuted;

void operatorControl() {
	AutoCodeExecuted=false;
	while (1) {
		LeftStickVert=joystickGetAnalog(1, 2);
		RightStickVert=joystickGetAnalog(1, 3);
		TroughUp=joystickGetDigital(1,5,JOY_UP);
		TroughDown=joystickGetDigital(1,5,JOY_DOWN);
		ScoopArmUp=joystickGetDigital(1,6,JOY_UP);
		ScoopArmDown=joystickGetDigital(1,6,JOY_DOWN);
		ScoopGateUpLeft=joystickGetDigital(1,7,JOY_LEFT);
		ScoopGateDownLeft=joystickGetDigital(1,7,JOY_RIGHT);
		ScoopGateUpRight=joystickGetDigital(1,8,JOY_RIGHT);
		ScoopGateDownRight=joystickGetDigital(1,8,JOY_LEFT);
		//Partner Controller
		PartTroughUp=joystickGetDigital(2,5,JOY_UP);
		PartTroughDown=joystickGetDigital(2,5,JOY_DOWN);
		PartScoopArmUp=joystickGetDigital(2,6,JOY_UP);
		PartScoopArmDown=joystickGetDigital(2,6,JOY_DOWN);
		PartScoopGateUpLeft=joystickGetDigital(2,7,JOY_LEFT);
		PartScoopGateUpRight=joystickGetDigital(2,8,JOY_LEFT);
		PartScoopGateDownLeft=joystickGetDigital(2,7,JOY_RIGHT);
		PartScoopGateDownRight=joystickGetDigital(2,8,JOY_RIGHT);
		//Base Control
		//Left Wheels
		if ((joystickGetDigital(1,8,JOY_DOWN)==1)&&(joystickGetDigital(1,7,JOY_DOWN)==1)){// Must be initiated on primary controller
			if (AutoCodeExecuted==true){

			}
			else {
				//AutoCodeExecuted=true;
				autocode();
			}
		}
    if (LeftStickVert!=0){
		  LeftWheels(LeftStickVert);
		}else{
			LeftWheels(0);
		}
	  //Right Wheels
	  if (RightStickVert!=0){
		  RightWheels(RightStickVert);
	  }else{
	    RightWheels(0);
	  }

		//Trough Control
		if(TroughUp || PartTroughUp){
		  troughSet(50);
	 }else if(TroughDown || PartTroughDown){
		  troughSet(-50);
		}else{
		  troughSet(0);
		}

		//Scoop Arm
		if(ScoopArmUp || PartScoopArmUp){
		  scoopArmSet(50);
		}else if(ScoopArmDown || PartScoopArmDown){
		  scoopArmSet(-50);
		}else{
		 scoopArmSet(0);
		}

		//Scoop Gate/Hugger
		if(ScoopGateUpLeft || PartScoopGateUpLeft){
		  scoopGateSetLeft(50);
		}else if(ScoopGateDownLeft || PartScoopGateDownLeft){
		  scoopGateSetLeft(-50);
		}else{
		 scoopGateSetLeft(0);
		}
		if(ScoopGateUpRight || PartScoopGateUpRight){
		  scoopGateSetRight(50);
		}else if(ScoopGateDownRight || PartScoopGateDownRight){
		  scoopGateSetRight(-50);
		}else{
		 scoopGateSetRight(0);
		}
	}//End While
}//End Optcontrol
