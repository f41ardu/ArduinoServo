/**
 * Generate servo-signal on digital pins #4 #5 #6 #7 with a frequency of 250Hz (4ms period).
 * Direct port manipulation is used for performances.
 *
 * This function might not take more than 2ms to run, which lets 2ms remaining to do other stuff.
 *
 * @see https:// www.arduino.cc/en/Reference/PortManipulation
 */
void applyMotorSpeed() {
    // Refresh rate is 250Hz: send ESC pulses every 4000µs
    while ((now = micros()) - loop_timer < period);

    // Update loop timer
    loop_timer = now;

    // Set pins #4 #5 #6 #7 HIGH
    PORTD |= B11110000;

    // Wait until all pins #4 #5 #6 #7 are LOW
    while (PORTD >= 16) {
        //now        = micros();
        difference = micros() - loop_timer;

        if (difference >= esc1) PORTD &= B11101111; // Set pin #4 LOW
        if (difference >= esc2) PORTD &= B11011111; // Set pin #5 LOW
        if (difference >= esc3) PORTD &= B10111111; // Set pin #6 LOW
        if (difference >= esc4) PORTD &= B01111111; // Set pin #7 LOW
    }
}
