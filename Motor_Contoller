class Potentiometer {
    protected:
        AnalogIn inputSignal;
        float VDD, currentSamplePC, currentSampleVolts;
    public:
        Potentiometer(PinName pin, float v) : inputSignal(pin), VDD(v) {}
        float amplitudeVolts(void) { return (inputSignal.read()*VDD); }
        float amplitudePC(void) { return inputSignal.read(); };
        void sample(void){
            currentSamplePC = inputSignal.read();
            currentSampleVolts = currentSamplePC * VDD;
        }
        float getCurrentSampleVolts(void){return currentSampleVolts; }
        float getCurrentSamplePC(void){return currentSamplePC; }
};

class SamplingPotentiometer : public Potentiometer {
    private:
    Ticker sp_tkr;
    float sampling_period, sampling_frequency;
    public:
    SamplingPotentiometer(PinName pin, float v, float sampling_frequency): Potentiometer(pin, v), sampling_frequency(sampling_frequency){
        sampling_period = (1/sampling_frequency);
        sp_tkr.attach(callback(this, &Potentiometer::sample), sampling_period);  //Samples the potentiometer and stores values in member function every nth period
    }
   
};

 class Potentiometer {
    protected:
        AnalogIn inputSignal;
        float VDD, currentSamplePC, currentSampleVolts;
    public:
        Potentiometer(PinName pin, float v) : inputSignal(pin), VDD(v) {}
        float amplitudeVolts(void) { return (inputSignal.read()*VDD); }
        float amplitudePC(void) { return inputSignal.read(); };
        void sample(void){
            currentSamplePC = inputSignal.read();
            currentSampleVolts = currentSamplePC * VDD;
        }
        float getCurrentSampleVolts(void){return currentSampleVolts; }
        float getCurrentSamplePC(void){return currentSamplePC; }
};

class SamplingPotentiometer : public Potentiometer {
    private:
    Ticker sp_tkr;
    float sampling_period, sampling_frequency;
    public:
    SamplingPotentiometer(PinName pin, float v, float sampling_frequency): Potentiometer(pin, v), sampling_frequency(sampling_frequency){
        sampling_period = (1/sampling_frequency);
        sp_tkr.attach(callback(this, &Potentiometer::sample), sampling_period);  //Samples the potentiometer and stores values in member function every nth period
    }
   
};

class motor {
    protected:
    DigitalOut mode;
    DigitalOut direction;
    PwmOut PWMmotor;
    float frequency, dutycycle, period;
    public:
    motor(PinName md, PinName d, PinName pwm): mode(md), direction(d), PWMmotor(pwm){
        frequency = 20000.0;
        period = 1.0f/20000.0;
        mode.write(1);
        dutycycle = 0.5;
        PWMmotor.period_us(56);
        PWMmotor.write(dutycycle);
    }

    float get_d_cycle(void){
        return dutycycle;
    }
    void set_d_cycle(float duty){
        dutycycle = duty;
        PWMmotor.write(dutycycle);
    }

    void FSM_Motor(int selector){
        switch (selector)
        {
        case 0:
            dutycycle = 1.0; // backwards full speed
            PWMmotor.write(dutycycle);
            break;
        case 1:
            dutycycle = 0.0; // forwards full speed
            PWMmotor.write(dutycycle);
            break;
        case 2:
            dutycycle = 0.6; // backwards slow
            PWMmotor.write(dutycycle);
            break;
        case 3:
            dutycycle = 0.4; // forwards slow
            PWMmotor.write(dutycycle);
            break;
        case 4:
            dutycycle = 0.8; // backwards medium
            PWMmotor.write(dutycycle);
            break;
        case 5:
            dutycycle = 0.2; // forwards medium
            PWMmotor.write(dutycycle);
            break;
        default:
            dutycycle = 0.5; // forwards medium
            PWMmotor.write(dutycycle);
            break;
        }
    }

};
