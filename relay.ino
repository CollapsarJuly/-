#include "relay.h"


void relay_on()
{
    digitalWrite(relay,HIGH);
}

void relay_off()
{
    digitalWrite(relay,LOW);
}

void relay_init()
{
    pinMode(relay,OUTPUT);
    relay_off();
}