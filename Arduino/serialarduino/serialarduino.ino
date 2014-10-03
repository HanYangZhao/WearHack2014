// Do not remove the include below


int flexSensorPin[] = {A0,A1,A2,A3,A4};
int flex0to100[5];
int flexSensorReading1[5];
int flexSensorReading2[5];
int flexSensorReading3[5];
int flexSensorReading4[5];
int flexSensorReading5[5];
int result[5];
int hash = 0;
int reading_thumb = 0;
int reading_index = 0;
int reading_middle = 0;
int reading_ring = 0;
int reading_pinky = 0;
int reading[5];

boolean connect;

//The setup function is called once at startup of the sketch
void setup()
{

	pinMode(6, OUTPUT);
	   pinMode(3, OUTPUT);
	   pinMode(5, OUTPUT);
	   pinMode(12, OUTPUT);

	   Serial.begin(9600);
	   digitalWrite(6, HIGH);
	    digitalWrite(3, HIGH);
	     digitalWrite(5, HIGH);
	      digitalWrite(12, HIGH);
// Add your initialization code here
}

// The loop function is called in an endless loop
void loop(){

  reading_thumb = 0;
  reading_index = 0;
  reading_middle = 0;
  reading_ring = 0;
  reading_pinky= 0;

 for (int i = 0 ; i < 5 ; i++){
	flexSensorReading1[i]=  analogRead(flexSensorPin[0]);
    flexSensorReading2[i]=  analogRead(flexSensorPin[1]);
    flexSensorReading3[i]=  analogRead(flexSensorPin[2]);
    flexSensorReading4[i]=  analogRead(flexSensorPin[3]);
    flexSensorReading5[i]=  analogRead(flexSensorPin[4]);

   reading_thumb += flexSensorReading1[i];
   reading_index += flexSensorReading2[i];
   reading_middle += flexSensorReading3[i];
   reading_ring += flexSensorReading4[i];
   reading_pinky += flexSensorReading5[i];
 }

  reading_thumb = reading_thumb / 5;
  reading_index = reading_index / 5;
  reading_middle = reading_middle / 5;
  reading_ring = reading_ring / 5;
  reading_pinky = reading_pinky / 5;

  reading[0] = reading_thumb;
  reading[1] = reading_index;
  reading[2] = reading_middle;
  reading[3] = reading_ring;
  reading[4] = reading_pinky;
  
  if(Serial.read() == '1')
     connect = true;
  
  
if(connect == true){
  for(int i = 0 ; i<5 ; i++){
          Serial.println(reading[i]);
  	 
  	  
  }
}
delay(500);
}

