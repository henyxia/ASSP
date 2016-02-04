// Pinout Moteur NEMA 17 pour l'axe X
#define pinStepX   2  // Signal de PAS (avancement)
#define pinMS1X    22 // Bit 1 de selection du micro pas 
#define pinMS2X    23 // Bit 2 de selection du micro pas
#define pinMS3X    24 // Bit 3 de selection du micro pas 
#define pinEnableX 25 // Activation du driver/pilote
#define pinDirX    26 // Direction

// Pinout Moteur NEMA 17 pour l'axe Y
#define pinStepY   3  // Signal de PAS (avancement)
#define pinMS1Y    27 // Bit 1 de selection du micro pas 
#define pinMS2Y    28 // Bit 2 de selection du micro pas
#define pinMS3Y    29 // Bit 3 de selection du micro pas 
#define pinEnableY 30 // Activation du driver/pilote
#define pinDirY    31 // Direction

// Pinout Moteur stepper-glissière pour translation selon Z (Seeed)
#define pinStepZ   4  // Signal de PAS (avancement)
#define pinMS1Z    32 // Bit 1 de selection du micro pas 
#define pinMS2Z    33 // Bit 2 de selection du micro pas
#define pinMS3Z    34 // Bit 3 de selection du micro pas 
#define pinEnableZ 35 // Activation du driver/pilote
#define pinDirZ    36 // Direction

void setup()
{
	// Serial init
	Serial.begin(9600);

	// NEMA X
	pinMode(pinEnableX, OUTPUT);
	pinMode(pinStepX, OUTPUT);
	pinMode(pinDirX, OUTPUT);
	pinMode(pinMS1X, OUTPUT);
	pinMode(pinMS2X, OUTPUT);
	pinMode(pinMS3X, OUTPUT);

	// NEMA Y
	pinMode(pinEnableY, OUTPUT);
	pinMode(pinStepY, OUTPUT);
	pinMode(pinDirY, OUTPUT);
	pinMode(pinMS1Y, OUTPUT);
	pinMode(pinMS2Y, OUTPUT);
	pinMode(pinMS3Y, OUTPUT);

	// Seeed Z
	pinMode(pinEnableZ, OUTPUT);
	pinMode(pinStepZ, OUTPUT);
	pinMode(pinDirZ, OUTPUT);
	pinMode(pinMS1Z, OUTPUT);
	pinMode(pinMS2Z, OUTPUT);
	pinMode(pinMS3Z, OUTPUT);

	Serial.print("I00");
}

void loop()
{
	bool		waitingForInstructions = true;
	uint32_t	axpos = 0;
	uint32_t	aypos = 0;
	uint32_t	azpos = 0;
	uint32_t	wxpos = 0;
	uint32_t	wypos = 0;
	uint32_t	wzpos = 0;
	uint8_t		cmd;

	//Init des sorties
	digitalWrite(pinEnableX, LOW);  // Activation driver (logique inversée) 
	digitalWrite(pinDirX, HIGH); // Dir = 1 <=> Sens trigonométrique
	digitalWrite(pinStepX, LOW);  // Initialisation de la broche step
	digitalWrite(pinMS1X, LOW);  // Choix du micro pas (MS1..3 = 0 0 0 pour Full Step)
	digitalWrite(pinMS2X, LOW);
	digitalWrite(pinMS3X, LOW);
  
	digitalWrite(pinEnableY, LOW);  // Activation driver (logique inversée) 
	digitalWrite(pinDirY, HIGH); // Dir = 1 <=> Sens trigonométrique
	digitalWrite(pinStepY, LOW);  // Initialisation de la broche step
	digitalWrite(pinMS1Y, LOW);  // Choix du micro pas (MS1..3 = 0 0 0 pour Full Step)
	digitalWrite(pinMS2Y, LOW);
	digitalWrite(pinMS3Y, LOW);
  
	digitalWrite(pinEnableZ, LOW);  // Activation driver (logique inversée) 
	digitalWrite(pinDirZ, HIGH); // DirZ = 1 <=> Descendre
	digitalWrite(pinStepZ, LOW);  // Initialisation de la broche step
	digitalWrite(pinMS1Z, LOW);  // Choix du micro pas (MS1..3 = 1 0 0 pour Half Step)
	digitalWrite(pinMS2Z, LOW);
	digitalWrite(pinMS3Z, LOW);

	Serial.print("I01");
	while(Serial.available() <= 0);
	Serial.read();

	Serial.print("I02");
	/*
	while(waitingForInstructions)
	{
		while(Serial.available() <= 0);
		cmd = Serial.read();
		if(cmd == 'X')
		{
			wxpos = 0;
			while(Serial.available() <= 0);
			cmd = Serial.read();
			wxpos += (cmd << 24);
			while(Serial.available() <= 0);
			cmd = Serial.read();
			wxpos += (cmd << 16);
			while(Serial.available() <= 0);
			cmd = Serial.read();
			wxpos += (cmd << 8);
			while(Serial.available() <= 0);
			cmd = Serial.read();
			wxpos += cmd;
			Serial.println("I03");
			Serial.println(wxpos, HEX);
			Serial.println(wxpos, DEC);
		}
		else if(cmd == 'Y')
		{
		}
		else if(cmd == 'G')
		{
		}
		else
			Serial.print("E00");
	}
	*/

	uint8_t runX = 0;
	uint8_t runY = 0;

	while(1)
	{
		if(Serial.available() > 0)
		{
			Serial.println("CMD RECV");
			cmd = Serial.read();
			if(cmd == 'U')
				runX = 1;
			if(cmd == 'u')
				runX = 0;
			if(cmd == 'L')
				runY = 1;
			if(cmd == 'l')
				runY = 0;
		}
		if(runX)
			digitalWrite(pinStepX, HIGH);
		if(runY)
			digitalWrite(pinStepY, HIGH);
	    delay(4);
		if(runX)
			digitalWrite(pinStepX, LOW);
		if(runY)
			digitalWrite(pinStepY, LOW);
	    delay(4);
	}
}











