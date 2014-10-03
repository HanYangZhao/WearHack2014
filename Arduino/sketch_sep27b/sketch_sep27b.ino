#include <QueueList.h>

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
int reading_pinky= 0;
int reading[5];
String alphabet[] = {"a","b","c","d","e","f","g","h","i","k","l","m","n","o","p","q","r","s","t","u","w","x","y","z"};
int alphabetCounter[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
QueueList <String> potentialLetters;

int matrix[25][5] = { 
{437,325,342,366,411},		
{388,468,464,471,462},		
{375,318,332,378,443},		
{400,461,366,382,440},		
{397,320,346,364,395},		
{408,413,458,456,454},		
{393,462,336,363,384},		
{375,464,464,371,411},		
{381,327,373,369,461},		
{452,465,450,374,406},			
{449,459,328,349,375},		
{414,442,447,417,405},		
{430,375,393,383,393},		
{440,367,394,398,417},		
{450,466,410,372,373},		
{442,451,338,349,391},		
{417,472,442,372,385},		
{447,466,428,378,390},		
{438,298,340,358,374},		
{446,385,350,372,409},		
{412,470,467,468,391},			
{372,392,355,367,403},			
{448,317,360,381,466},			
{386,461,368,373,428}
};	
          
void setup(){
   pinMode(6, OUTPUT);
   pinMode(3, OUTPUT);
   pinMode(5, OUTPUT);
    pinMode(12, OUTPUT);
     
  Serial.begin(9600);
   digitalWrite(6, HIGH);
    digitalWrite(3, HIGH);
     digitalWrite(5, HIGH);
      digitalWrite(12, HIGH);
}

int alphabetLookup(char a, String alphabet[]);
void compare(int input, int definition, QueueList <String> queue, String alphabet);
void queueExtract(QueueList <String>  queue, int alphabetCounter[], String alphabet[]);
char alphabetExtract( int alphabetCounter[]);

void loop(){
  
  while (!potentialLetters.isEmpty ()){
    (potentialLetters.pop());
  }
  
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
  
  for ( int i = 0 ; i < 5 ; i++){
   Serial.println(reading[i]);
  }
  for ( int j = 0 ; j < 5 ; j++){   
    for (int i = 0 ; i < 23 ; i++){
      (compare(reading[j],matrix[i][j],potentialLetters, alphabet[i]));
      
    }
  }
  
  queueExtract(potentialLetters, alphabetCounter, alphabet);
  Serial.println(alphabetExtract(alphabetCounter));
    
  delay(5000); //just here to slow down the output for easier reading
}

// compare(reading_[1] , 2DArray[i][1], queue)
void compare(int input, int definition, QueueList <String> queue, String alphabet) {
  if (definition >= input -10 && definition <= input + 10)
        //Serial.println(alphabet);
        queue.push( alphabet);
       Serial.println(queue.count()); 
}

char alphabetExtract( int alphabetCounter[]){
   char result = 0;
   for ( int i = 0 ; i < 23 ; i++ ){
        if (result < alphabetCounter[i])
          result = alphabetCounter[i]; 
  }
}
  
int alphabetLookup(String a, String alphabet[]){
  for (int i=0; i < 23; i++) {
    if (a = alphabet[i]) {
       Serial.println(i);
       return i;
       
       break;
    }
  }
}

void queueExtract(QueueList <String>  queue, int alphabetCounter[], String alphabet[]){
  Serial.println("in queue");
  while (!queue.isEmpty()){ 
    
    String poped = queue.pop();
    Serial.println(poped);
    int index = alphabetLookup(poped, alphabet);
    alphabetCounter[index] += 1;
  }  
}


