#include "mbed.h"
#include"QEI.h"        //for the encoder                                                            /* source https://developer.mbed.org/cookbook/QEI */
#include "MotorController.h"  // 2 motor needs to be declared in main
#include "C12832.h"
#include "EncoderWrapper.h"
C12832 lcd(D11, D13, D12, D7, D10);
DigitalOut enable(PB_13);

int main() {
    motor Rmotor(PA_13, PA_14, PA_15);
    motor Lmotor(PC_14, PC_15, PB_7);
    QEI* encoder_right = new QEI(PB_14, PB_15, NC, 256, QEI::X2_ENCODING);
    QEI* encoder_left = new QEI(PC_2, PC_3, NC, 256, QEI::X2_ENCODING);

    encoder encode(encoder_right, encoder_left);

    enable = 1;

    while(1) {
        Rmotor.FSM_Motor(0);
        Lmotor.FSM_Motor(0);
        lcd.locate(3,0);
        lcd.printf("Right Wheel Velocity: %d", encoder_right -> getPulses());
        lcd.locate(3,10);
        lcd.printf("Left Wheel Velocity: %.2f", encode.get_wheel_velocity_left());
        lcd.locate(3,20);
        lcd.printf("Translational Velocity: %.2f", encode.get_robot_trans_vel());
        wait(5);
        Rmotor.FSM_Motor(1);
        Lmotor.FSM_Motor(1);
        lcd.locate(3,0);
        lcd.printf("Right Wheel Velocity: %f", encode.get_wheel_velocity_right());
        lcd.locate(3,10);
        lcd.printf("Left Wheel Velocity: %f", encode.get_wheel_velocity_left());
        lcd.locate(3,20);
        lcd.printf("Translational Velocity: %f", encode.get_robot_trans_vel());
        wait(5);
        Rmotor.FSM_Motor(2);
        Lmotor.FSM_Motor(3);
        lcd.locate(3,0);
        lcd.printf("Right Wheel Velocity: %f", encode.get_wheel_velocity_right());
        lcd.locate(3,10);
        lcd.printf("Left Wheel Velocity: %f", encode.get_wheel_velocity_left());
        lcd.locate(3,20);
        lcd.printf("Translational Velocity: %f", encode.get_robot_trans_vel());
        wait(5);
        lcd.locate(3,0);
        lcd.printf("Right Wheel Velocity: %d", encode.get_wheel_velocity_right());
        lcd.locate(3,10);
        lcd.printf("Left Wheel Velocity: %d", encode.get_wheel_velocity_left());
        lcd.locate(3,20);
        lcd.printf("Translational Velocity: %d", encode.get_robot_trans_vel());
        Rmotor.FSM_Motor(5);
        Lmotor.FSM_Motor(4);
        wait(5);
        }
    }
