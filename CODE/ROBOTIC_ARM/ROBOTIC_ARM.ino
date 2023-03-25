
#define veh_x A2
#define veh_y A3
#define arm_x A1
#define arm_y A0
#define sw 3

void setup() {
  // put your setup code here, to run once:
pinMode(veh_x,INPUT);
pinMode(veh_y,INPUT);
pinMode(arm_x,INPUT);
pinMode(arm_y,INPUT);
pinMode(sw,INPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
int veh_ax=analogRead(veh_x);
int veh_ay=analogRead(veh_y);

int arm_ax=analogRead(arm_x);
int arm_ay=analogRead(arm_y);

arm_ay = map(arm_ay, 0, 1024, 300, 600);
int ud= map(arm_ax, 0, 1024, 550, 350);
int fb= map(arm_ax, 0, 1024, 600, 300);

Serial.print("#");
Serial.print(ud);
Serial.print(",");
Serial.print(fb);
Serial.print(",");
Serial.print(arm_ay);
Serial.print("*");

if(digitalRead(sw)==LOW)
{
 Serial.println('a'); 
 while(digitalRead(sw)==LOW);
}

if(veh_ax<400)
{
Serial.println('r');  
}
if(veh_ax>600)
{
Serial.println('l');  
}
if(veh_ay<400)
{
Serial.println('f');  
}
if(veh_ay>600)
{
Serial.println('b');  
}

if((veh_ax>400&&veh_ax<600)&&(veh_ay>400&&veh_ay<600))
{
  Serial.println('s'); 
  }




delay(500);


}
