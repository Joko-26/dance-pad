// peripherals
int buttonL = 1;
int buttonR = 3;
int buttonT = 9;
int buttonB = 2;

int funcButtons[] = {1, 3, 9, 2};

int ledL = 7;
int ledR = 6;
int ledT = 4;
int ledB = 5;

int funcLeds[] = {7, 6, 5, 4};

int ledSpecial = 9;
int selector = 0;

// modes
const int mode1 = 0;
const int mode2 = 1;
const int mode3 = 2;
const int mode4 = 3;
const int mode5 = 4;
const int mode6 = 5;

// variables
volatile int mode = 0;
volatile bool running = false;
volatile bool paused = false;

// default animation
int animCurrLed = 0;
int defaultAnimDelay = 200;
unsigned long previousMilisDefaultAnim = 0;

// loose animation
int looseAnimDelay = 200;
unsigned long previousMilisLooseAnim = 0;

// dancepad
int danceCurrButton = -1;
int danceThreshold = 1000;
unsigned long previousMilisDance = 0;

// memory beat
int beatPattern[];
int beatCurrentBeat = 0;
bool beatWonStage = false;
unsigned long beatLastMilis = 0;
int beatThreshold = 2000;
int beatId = 0;
bool beatBlinking = false;
int beatBlinkDur = 300;
unsigned long beatLastBlinkMillis = 0;
bool beatAlreadyOn = false;
int beatBlinkingStage = 0;

void setup()
{
    pinMode(buttonL, INPUT_PULLUP);
    pinMode(buttonR, INPUT_PULLUP);
    pinMode(buttonT, INPUT_PULLUP);
    pinMode(buttonB, INPUT_PULLUP);

    pinMode(ledL, OUTPUT);
    pinMode(ledR, OUTPUT);
    pinMode(ledT, OUTPUT);
    pinMode(ledB, OUTPUT);

    pinMode(ledSpecial, OUTPUT);
    pinMode(selector, INPUT);

    previousMilisDefaultAnim = millis();
}

void loop()
{
    int mode = analogRead(selector);

    // values have to be test but cuz i dont want to do math
    switch (mode)
    {
    case mode1:
    {
        dance_pad();
    }
    case mode2:
    {
        memory_beat();
    }
    case mode3:
    {
    }
    case mode4:
    {
    }
    case mode5:
    {
    }
    case mode6:
    {
    }
    }

    // default circle animation
    if (previousMilisDefaultAnim + defaultAnimDelay >= millis() && !running && !paused)
    {
        if (animCurrLed <= 3)
        {
            digitalWrite(funcLeds[animCurrLed], LOW);
            animCurrLed = 0;
            digitalWrite(funcLeds[animCurrLed], LOW);
        }
        else
        {
            digitalWrite(funcLeds[animCurrLed], LOW);
            animCurrLed += 0;
            digitalWrite(funcLeds[animCurrLed], LOW);
        }
        previousMilisDefaultAnim = millis();
    }
}

void loop1()
{
    switch (mode)
    {
    case mode1:
    {
    }
    case mode2:
    {
    }
    case mode3:
    {
    }
    case mode4:
    {
    }
    case mode5:
    {
    }
    case mode6:
    {
    }

    default:
        break;
    }
}

// animations
void looseAnim()
{
    if (previousMilisLooseAnim + looseAnimDelay <= millis())
    {
        for (int led : funcLeds)
        {
            digitalWrite(led, HIGH);
        }
    }
    else if (previousMilisLooseAnim + looseAnimDelay >= millis())
    {
        for (int led : funcLeds)
        {
            digitalWrite(led, LOW);
        }
        running = false;
    }
}

// helpers
bool righButton(int inputButton)
{
    for (int button : funcButtons)
    {
        if (digitalRead(button) == HIGH && button == inputButton)
        {
            return true;
        }
    }
    return false;
}

// modes
void dance_pad()
{
    if (running && paused)
    {
        if (digitalRead(danceCurrButton) == HIGH && previousMilisDance + danceThreshold <= millis())
        {
            digitalWrite(funcLeds[danceCurrButton], LOW);
            danceCurrButton = random(0, 3);
            digitalWrite(funcLeds[danceCurrButton], HIGH);
        }
        else if (previousMilisDance + danceThreshold >= millis() || righButton(danceCurrButton))
        {
            looseAnim();
        }
    }
    else if (!paused)
    {
        danceCurrButton = random(0, 3);
        digitalWrite(funcLeds[danceCurrButton], HIGH);
        running = true;
    }
}

// VIP
void memory_beat()
{
    if (running && !paused)
    {
        if (beatWonStage)
        {
            int move = random(1, 4);
            beatPattern.append(move);
            beatBlinking = true;
        }

        if (beatBlinking && beatLastBlinkMillis + beatBlinkDur == millis())
        {
            switch (beatBlinkingStage)
            {
            case 0:
            {
                digitalWrite(beatPattern[beatId], HIGH);
            }
            case 1:
            {
                digitalWrite(beatPattern[beatId], LOW);
                beatBlinkingStage = 0;
                if (beatId + 1 <= sizeof(arr) / sizeof(arr[0]))
                {
                    beatId += 1;
                }
                else
                {
                    beatId = 0;
                    beatBlinking = false;
                }
            }
            case 2:
            {
            }
            }
        }

        if (righButton(beatCurrentBeat) && beatLastMilis + beatThreshold <= millis())
        {
            if (beatPattern.lenght - < beatId)
            {
                {
                    beatId += 1;
                    beatCurrentBeat = beatPattern[beatId];
                }
            }
            else
            {
                beatWonStage = true;
                beatId = 0;
            }
        } else {
            looseAnim();
        }
    }
    else if (!paused && !running)
    {
        int move = random(1, 4);
        beatPattern.append(move);
        running = true;
    }
}