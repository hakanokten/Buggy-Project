class encoder {
 private:
    QEI* encoder_left;
    QEI* encoder_right;
    unsigned long cetr, cetl, petr, petl;
    int sampt_r, sampt_l;
    float etrl, etrr,rtv, rav;
    float wvr, wvl;
    float dbw;
    float wheel_diameter;
    float CPR;
    //Ticker calc_display;
    Timer t_left, t_right;
 
 public:
    encoder(QEI* enc, QEI* enc2) : encoder_left(enc), encoder_right(enc2) {
        //sampt = 0.1f;
        dbw = 0.17;
        petl = 0;
        petr = 0;
        sampt_l = 0;
        sampt_r = 0;
        wheel_diameter = 0.084;
        enc -> reset();
        enc2 -> reset();
        t_left.reset();
        t_right.reset();
        t_left.start();
        t_right.start();
        
        //calc_display.attach(callback(this, &encoder::display_val), sampt);
    }
   
    /*void display_val(void){  
        cetl = (encoder_left -> getPulses());
        etrl = ( (float) cetl - petl)/sampt;
        petl = cetl;  
       
        cetr = (encoder_right -> getPulses());
        etrr = ( (float) cetr - petr)/sampt;
        petr = cetr;
         
        wvr =  etrr * CPR * ((wheel_diameter * 3.14159f));
        wvl =  etrl * CPR * ((wheel_diameter * 3.14159f));
        rtv = (wvr + wvl)/ 2;
        rav = (wvr - wvl)/dbw;
   
    }  */
   
    float get_wheel_velocity_right(void) {
        cetr = (encoder_right -> getPulses());
        sampt_r = t_right.read_us();
        etrr = (( (float) cetr - petr)/512.0f)/(sampt_r/1000000.0f);
        petr = cetr; 
        t_right.reset();
        t_right.start();
        wvr =  (etrr * ((wheel_diameter * 3.14159f)));
        return wvr;    
    }
   
    float get_wheel_velocity_left(void) {
        cetl = (encoder_left -> getPulses());
        sampt_l = t_left.read_us();
        etrl = (( (float) cetl - petl)/512.0f)/(sampt_l/1000000.0f);
        petl = cetl; 
        t_left.reset();
        t_left.start();
        wvl =  (etrl * ((wheel_diameter * 3.14159f)));
        return wvl; 
    }
   
    float get_robot_trans_vel(void) {
        wvl = get_wheel_velocity_left();
        wvr = get_wheel_velocity_right();
        rtv = (wvr + wvl)/ 2;
        return rtv;
    }
   
    float get_robot_ang_vel(void) {
        wvl = get_wheel_velocity_left();
        wvr = get_wheel_velocity_right();
        rav = (wvr - wvl)/dbw;
        return rav;
    }

};
