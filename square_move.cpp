#include "mbed.h"
#include "QEI.h"
#include "MotorController.h"
#include "EncoderWrapper.h"
#include "C12832.h"

int main() {
    C12832 lcd(D11, D13, D12, D7, D10);
    DigitalOut enable(PB_13);
    int i=0, lcount, Last_tcount=0,tcount;
    motor Rmotor(PA_13, PA_14, PA_15);
    motor Lmotor(PC_14, PC_15, PB_7);
    QEI* encoder_right = new QEI(PB_14, PB_15, NC, 256, QEI::X2_ENCODING);
    QEI* encoder_left = new QEI(PC_2, PC_3, NC, 256, QEI::X2_ENCODING);
    encoder Encoder(encoder_left, encoder_right);
    enable = 1;
    
    while((encoder_left -> getPulses()) < 900){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_left -> getPulses());
        Rmotor.set_d_cycle(0.30);
        Lmotor.set_d_cycle(0.30);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();

    while((encoder_left -> getPulses()) < 340){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_left -> getPulses());
        Rmotor.set_d_cycle(0.7);
        Lmotor.set_d_cycle(0.3);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();
    
    while((encoder_left -> getPulses()) < 900){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_left -> getPulses());
        Rmotor.set_d_cycle(0.30);
        Lmotor.set_d_cycle(0.30);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();

    while((encoder_left -> getPulses()) < 340){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_left -> getPulses());
        Rmotor.set_d_cycle(0.7);
        Lmotor.set_d_cycle(0.3);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();
    
    while((encoder_left -> getPulses()) < 900){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_left -> getPulses());
        Rmotor.set_d_cycle(0.30);
        Lmotor.set_d_cycle(0.30);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();

    while((encoder_left -> getPulses()) < 340){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_left -> getPulses());
        Rmotor.set_d_cycle(0.7);
        Lmotor.set_d_cycle(0.3);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();
    
    while((encoder_left -> getPulses()) < 900){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_left -> getPulses());
        Rmotor.set_d_cycle(0.30);
        Lmotor.set_d_cycle(0.30);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();
    
    //// turn around
    while((encoder_left -> getPulses()) < 680){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_left -> getPulses());
        Rmotor.set_d_cycle(0.7);
        Lmotor.set_d_cycle(0.3);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();
    
     while((encoder_left -> getPulses()) < 900){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_right -> getPulses());
        Rmotor.set_d_cycle(0.30);
        Lmotor.set_d_cycle(0.30);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();

    while((encoder_left -> getPulses()) > -340){
        lcd.locate(3, 0);
        lcd.printf("l count : %d", encoder_left -> getPulses());
        Rmotor.set_d_cycle(0.3);
        Lmotor.set_d_cycle(0.7);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();
    
     while((encoder_left -> getPulses()) < 900){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_right -> getPulses());
        Rmotor.set_d_cycle(0.30);
        Lmotor.set_d_cycle(0.30);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();

    while((encoder_left -> getPulses()) > -340){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_right -> getPulses());
        Rmotor.set_d_cycle(0.3);
        Lmotor.set_d_cycle(0.7);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();
    
     while((encoder_left -> getPulses()) < 900){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_right -> getPulses());
        Rmotor.set_d_cycle(0.30);
        Lmotor.set_d_cycle(0.30);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();

    while((encoder_left -> getPulses()) > -340){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_left -> getPulses());
        Rmotor.set_d_cycle(0.3);
        Lmotor.set_d_cycle(0.7);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();
    
    while((encoder_left -> getPulses()) < 900){
        lcd.locate(3, 0);
        lcd.printf("count : %d", encoder_right -> getPulses());
        Rmotor.set_d_cycle(0.30);
        Lmotor.set_d_cycle(0.30);
    }
    Rmotor.set_d_cycle(0.5);
    Lmotor.set_d_cycle(0.5);
    wait(0.5);
    encoder_left -> reset();
    
