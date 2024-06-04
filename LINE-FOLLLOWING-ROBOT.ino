// Motor and sensor pin definitions
// Right Motor
#define enA 5
#define in1 2
#define in2 3
// Left Motor
#define in3 4
#define in4 9
#define enB 6
#define s1 A0
#define s2 A1
#define s3 A2
#define s4 A3
#define s5 A4
#define constSpeed 150
#define sSpeed 150
#define highSpeed 200
int ReadS1;
int ReadS2;
int ReadS3;
int ReadS4;
int ReadS5;
#define BLACK 0
#define WHITE 1

//---------------------------------------------SETUP-----------------------------------------------------------

void setup()
{
    // Set timer frequency to 31.3kHz for PWM on pins 5 and 6
    TCCR0B = TCCR0B & B11111000 | B00000001;

    // Initialize motor and sensor pin modes
    pinMode(enA, OUTPUT);
    pinMode(enB, OUTPUT);
    pinMode(in1, OUTPUT);
    pinMode(in2, OUTPUT);
    pinMode(in3, OUTPUT);
    pinMode(in4, OUTPUT);
    pinMode(s1, INPUT_PULLUP);
    pinMode(s2, INPUT_PULLUP);
    pinMode(s3, INPUT_PULLUP);
    pinMode(s4, INPUT_PULLUP);
    pinMode(s5, INPUT_PULLUP);

    // Ensure motor pins are initially low
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);

    // Begin serial communication
    Serial.begin(9600);
}

//---------------------------------------------FUNCTIONS-------------------------------------------------------

// Function to read sensor inputs
void ir()
{
    ReadS1 = digitalRead(s1);
    ReadS2 = digitalRead(s2);
    ReadS3 = digitalRead(s3);
    ReadS4 = digitalRead(s4);
    ReadS5 = digitalRead(s5);
}

// Function to control the manual car
void controlManualCar()
{
    ir();

    // Checking sensor inputs to determine movement
    if ((ReadS1 == BLACK) && (ReadS2 == BLACK) && (ReadS3 == BLACK) && (ReadS4 == BLACK) && (ReadS5 == BLACK))
    {
        stop();
    }
    else if ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == WHITE) && (ReadS4 == WHITE) && (ReadS5 == WHITE))
    {
        stop();
    }
    else if ((ReadS1 == BLACK) && (ReadS2 == WHITE) && (ReadS3 == WHITE) && (ReadS4 == WHITE) && (ReadS5 == BLACK))
    {
        stop();
    }
    else if ((ReadS1 == WHITE) && (ReadS2 == BLACK) && (ReadS3 == BLACK) && (ReadS4 == BLACK) && (ReadS5 == WHITE))
    {
        stop();
    }
    else if ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == BLACK) && (ReadS4 == WHITE) && (ReadS5 == WHITE))
    {

        while ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == BLACK) && (ReadS4 == WHITE) && (ReadS5 == WHITE))
        {
            moveforward(constSpeed);
            ir();
        }
    }
    else if ((ReadS1 == WHITE) && (ReadS2 == BLACK) && (ReadS3 == BLACK) && (ReadS4 == WHITE) && (ReadS5 == WHITE))
    {
        while ((ReadS1 == WHITE) && (ReadS2 == BLACK) && (ReadS3 == BLACK) &&
               (ReadS4 == WHITE) && (ReadS5 == WHITE))
        {
            TurnStopRight(sSpeed);
            ir();
        }
    }
    else if ((ReadS1 == WHITE) && (ReadS2 == BLACK) && (ReadS3 == WHITE) &&
             (ReadS4 == WHITE) && (ReadS5 == WHITE))
    {
        while ((ReadS1 == WHITE) && (ReadS2 == BLACK) && (ReadS3 == WHITE) &&
               (ReadS4 == WHITE) && (ReadS5 == WHITE))
        {
            TurnStopRight(sSpeed);
            ir();
        }
    }
    else if ((ReadS1 == BLACK) && (ReadS2 == WHITE) && (ReadS3 == WHITE) &&
             (ReadS4 == WHITE) && (ReadS5 == WHITE))
    {
        while ((ReadS1 == BLACK) && (ReadS2 == WHITE) && (ReadS3 == WHITE) &&
               (ReadS4 == WHITE) && (ReadS5 == WHITE))
        {
            TurnStopRight(sSpeed);
            ir();
        }
    }
    else if ((ReadS1 == BLACK) && (ReadS2 == BLACK) && (ReadS3 == WHITE) &&
             (ReadS4 == WHITE) && (ReadS5 == WHITE))
    {
        while ((ReadS1 == BLACK) && (ReadS2 == BLACK) && (ReadS3 == WHITE) &&
               (ReadS4 == WHITE) && (ReadS5 == WHITE))
        {
            TurnStopRight(sSpeed);
            ir();
        }
    }
    else if ((ReadS1 == BLACK) && (ReadS2 == BLACK) && (ReadS3 == BLACK) &&
             (ReadS4 == WHITE) && (ReadS5 == WHITE))
    {
        while ((ReadS1 == BLACK) && (ReadS2 == BLACK) && (ReadS3 == BLACK) &&
               (ReadS4 == WHITE) && (ReadS5 == WHITE))
        {
            TurnStopRight(sSpeed);
            ir();
        }
    }
    else if ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == BLACK) &&
             (ReadS4 == BLACK) && (ReadS5 == WHITE))
    {
        while ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == BLACK) &&
               (ReadS4 == BLACK) && (ReadS5 == WHITE))
        {
            TurnStopLeft(sSpeed);
            ir();
        }
    }
    else if ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == WHITE) &&
             (ReadS4 == BLACK) && (ReadS5 == WHITE))
    {
        while ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == WHITE) &&
               (ReadS4 == BLACK) && (ReadS5 == WHITE))
        {
            TurnStopLeft(sSpeed);
            ir();
        }
    }
    else if ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == WHITE) &&
             (ReadS4 == WHITE) && (ReadS5 == BLACK))
    {
        while ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == WHITE) &&
               (ReadS4 == WHITE) && (ReadS5 == BLACK))
        {
            TurnStopLeft(sSpeed);
            ir();
        }
    }
    else if ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == WHITE) &&
             (ReadS4 == BLACK) && (ReadS5 == BLACK))
    {
        while ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == WHITE) &&
               (ReadS4 == BLACK) && (ReadS5 == BLACK))
        {
            TurnStopLeft(sSpeed);
            ir();
        }
    }
    else if ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == BLACK) && (ReadS4 == BLACK) && (ReadS5 == BLACK))
    {
        while ((ReadS1 == WHITE) && (ReadS2 == WHITE) && (ReadS3 == BLACK) &&
               (ReadS4 == BLACK) && (ReadS5 == BLACK))
        {
            TurnStopLeft(sSpeed);
            ir();
        }
    }
}

// Function to move the car forward
void moveforward(int speed)
{
    Serial.println("forward");
    analogWrite(enA, speed);
    analogWrite(enB, speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

// Function to move the car backward
void moveBackward(int speed)
{
    Serial.println("backward");
    analogWrite(enA, speed);
    analogWrite(enB, speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW);
    digitalWrite(in4, HIGH);
}

// Function to turn the car right
void TurnStopRight(int speed)
{
    Serial.println("right");
    analogWrite(enA, speed);
    analogWrite(enB, speed);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH);
    digitalWrite(in4, LOW);
}

// Function to turn the car left
void TurnStopLeft(int speed)
{
    Serial.println("left");
    analogWrite(enA, speed);
    analogWrite(enB, speed);
    digitalWrite(in1, HIGH);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

// Function to stop the car
void stop()
{
    Serial.println("stop");
    analogWrite(enA, 0);
    analogWrite(enB, 0);
    digitalWrite(in1, LOW);
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW);
    digitalWrite(in4, LOW);
}

//---------------------------------------------MAIN LOOP-------------------------------------------------------

void loop()
{
    // Call the control function to manage the car's movement
    controlManualCar();
}
