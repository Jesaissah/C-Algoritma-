int randomled[]={2,3,4,5,6};
int buttons[]={8,9,10,11,12};
int memory[5];

void setup(){
  for(int i=0;i<5;i++){
    pinMode(randomled[i],OUTPUT);
    pinMode(butonlar[i],INPUT);
  }
  pinMode(13, OUTPUT);
  randomSeed(analogRead(0));
  randomize();
  precdict();
}
void loop(){ 
  
}
void randomize(){
  for (int i=0;i<5;i++){
    int index=random(0,5);
    memory[i]=randomled[index];
    digitalWrite(memory[i],HIGH);
    tone(13,750);
    delay(400);
    digitalWrite(memory[i],LOW);
    noTone(13);
    delay(400);
  }
}
void precdict(){
  for(int i=0;i<5;i++){
    int pressedbuton=-1;
      while(pressedbuton==-1){
      for(int j=0;j<5;j++){
      if(digitalRead(buttons[j])==HIGH){
      pressedbuton=randomled[j];
      digitalWrite(pressedbuton,HIGH);
      tone(13,850);
      while(digitalRead(buttons[j])==HIGH);
      noTone(13);
	    digitalWrite(pressedbuton,LOW);
      delay(100);
	  }
     }
   }
            if(pressedbuton!=memory[i]){
            tone(13,150);
            delay(2500);
            noTone(13);
            return;
            }
 }
      for(int f=400;f<1000;f+=100){
      tone(13,f);
      delay(250);  
    }
    tone(13,1200);
    delay(1000);
    noTone(13);
            
}
