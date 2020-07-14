class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle=30.0*hour;
        double minuteAngle=5.5*minutes;
        double x=abs(fmod(hourAngle-minuteAngle,360));
        return x>180?360-x:x;
    }
};