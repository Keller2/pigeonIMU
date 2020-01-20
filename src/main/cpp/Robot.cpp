/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <iostream>
#include <rev/CANSparkMax.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include "ctre/Phoenix.h"
  int Yaw;
std::shared_ptr<rev::CANSparkMax> Neo7;
void Robot::RobotInit() {
 
 // m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  //m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
  
  Neo7.reset(new rev::CANSparkMax(7, rev::CANSparkMaxLowLevel::MotorType::kBrushless));
  
  std::cout << "Hello I have started"  << std::endl << std::flush;

  IMU.reset(new PigeonIMU(17));

  std::cout << "Initialized the little pigeon" << std::endl << std::flush;
 
  //int Pitch = 0;
 
}

/**
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {
  //std::cout << "RobotPeriodic" << std::endl << std::flush;
  // std::cout << "Teleophas started" << std::endl << std::flush;
  //int val = IMU->GetYawPitchRoll(0);
  //std::cout << val << std::endl; 
   //std::cout << "val" << std::endl;
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
//  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
 // std::cout << "Auto selected: " << m_autoSelected << std::endl;
std::cout << "AutonomousStart" << std::endl << std::flush;
 // if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
 // } else {
    // Default Auto goes here
 // }
}

void Robot::AutonomousPeriodic() {
  //if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
 // } else {
   std::cout << "AutonomousPeriodic" << std::endl << std::flush;
    // Default Auto goes here
 // }
}


void Robot::DisabledInit() {
  
  
}

void Robot::DisabledPeriodic()
{

}

void Robot::TeleopInit() {
  //Neo7->Set(0);
 
}



void Robot::TeleopPeriodic() {
 //  std::shared_ptr<rev::CANSparkMax> Neo7;
   std::cout << "val" << std::endl;
   double ypr[3];
   //std::cout << "Doubled Value" << std::endl;
PigeonIMU(17).GetYawPitchRoll(ypr);
std::cout << ypr[0] << "Yaw" <<  ypr[1] <<"Pitch" << ypr[2] << "Roll"<<std::endl << std::flush;
//Neo7->Set(0.2);

Yaw = ypr[0];
std::cout << Yaw <<std::endl;
if(Yaw > 0){
  Neo7->Set(0.1);
}
if(Yaw < 0){
  Neo7->Set(-0.1);
}
 

//std::cout << 0 << std::endl; 


}

void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
