/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       joey_school                                               */
/*    Created:      Wed May 26 2021                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    1, 2, 8, 9      
// Motor3               motor         3               
// Motor4               motor         4               
// Motor5               motor         5               
// Motor6               motor         6               
// Motor10              motor         10              
// Motor11              motor         11              
// Motor12              motor         12              
// Motor13              motor         13              
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// Right Motor - 1,2,3,4,5,6
// Left Motor - 8,9,10,11,12,13

#include "vex.h"


using namespace vex;
vex::competition    Competition;

vex::motor Right1 (vex::PORT1, vex::gearSetting::ratio18_1,true);
vex::motor Right2 (vex::PORT2, vex::gearSetting::ratio18_1,true);
vex::motor Right3 (vex::PORT3, vex::gearSetting::ratio18_1,true);
vex::motor Right4 (vex::PORT4, vex::gearSetting::ratio18_1,true);
vex::motor Right5 (vex::PORT5, vex::gearSetting::ratio18_1,true);
vex::motor Right6 (vex::PORT6, vex::gearSetting::ratio18_1,true);
vex::motor Left1 (vex::PORT8, vex::gearSetting::ratio18_1,false);
vex::motor Left2 (vex::PORT9, vex::gearSetting::ratio18_1,false);
vex::motor Left3 (vex::PORT10, vex::gearSetting::ratio18_1,false);
vex::motor Left4 (vex::PORT11, vex::gearSetting::ratio18_1,false);
vex::motor Left5 (vex::PORT12, vex::gearSetting::ratio18_1,false);
vex::motor Left6 (vex::PORT13, vex::gearSetting::ratio18_1, false);



//Motor Group
vex::motor_group d(Right1, Right2, Right3, Right4, Right5, Right6, Left1, Left2, Left3, Left4, Left5, Left6);

//Motor Left and Right Movement Group 
vex::motor_group r(Right1, Right2, Right3, Right4, Right5, Right6);
vex::motor_group l(Left1, Left2, Left3, Left4, Left5, Left6);
vex::drivetrain dt(l, r);
void pre_auton( void ) {
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
  
}
void autonomous( void ) {
    

}
void usercontrol(void){

while (1){

    l.setVelocity(((Controller1.Axis3.position(percent)*0.7)-(Controller1.Axis4.position(percent)*0.3)),percent);
    r.setVelocity(((Controller1.Axis3.position(percent)*0.7)+(Controller1.Axis4.position(percent)*0.7)),percent);
   vex::task::sleep(20); //Sleep the task for a short amount of time to prevent wasted resources.   
  }

  //int leftDirection = Controller1.Axis3.position(percent);
  //int rightDirection = Controller1.Axis2.position(percent);

  //l.spin(vex::forward, leftDirection, vex::percent);
 //r.spin(vex::forward, rightDirection, vex::percent);

  


}


int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

Left3.setReversed(true);
Left3.spin(vex::directionType::fwd);

Left4.setReversed(true);
Left4.spin(vex::directionType::fwd);

Left5.setReversed(true);
Left5.spin(vex::directionType::fwd);


Left6.setReversed(true);
Left6.spin(vex::directionType::fwd);
    l.spin(forward);
        r.spin(forward);
  
    if((Controller1.ButtonDown.pressing() or (Controller1.ButtonLeft.pressing() or (Controller1.ButtonRight.pressing() or Controller1.ButtonUp.pressing())))){
      l.setVelocity(600,velocityUnits::rpm);
      r.setVelocity(600,velocityUnits::rpm);
      if(Controller1.ButtonUp.pressing()){
        l.spin(forward);
        r.spin(forward);
      }
      if(Controller1.ButtonDown.pressing()){
        l.spin(reverse);
        r.spin(reverse);
      }
      if(Controller1.ButtonLeft.pressing()){
        l.spin(reverse);
        r.spin(forward);
      }
      if(Controller1.ButtonRight.pressing()){
        l.spin(forward);
        r.spin(reverse);
      }
    }
    //Prevent main from exiting with an infinite loop.                        
    while(1) {
      vex::task::sleep(100);//Sleep the task for a short amount of time to prevent wasted resources.
    }    
}
