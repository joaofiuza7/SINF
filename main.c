#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>


#define SIZE_OF_TOTAL 70


	float convv(int hvolt){
		float n=0;
		n = (hvolt/4096)*(1.5);
		return n;
	} //conversão tensão
	
	float convt(int htemp){
		float n1=0;
		n1 = 0.01*htemp - 39.6;
		return n1;
	} //conversão temperatura
	
	float convlv(int hlvis){
		float n2=0;
		n2 = 0.625*pow(10,6)*(hlvis/4096)*1.5 / 100;
		return n2;
	} //conversão luz visível
	
	float convli(int hlinf){
		float n3=0;
		n3 = 0.769 * pow(10,5) * (hlinf/4096) * 1.5 / 100;
		return n3;
	} //conversão luz infravermelha
	
	float convhumir(int hhumir){
		float n4=0;
		n4 = (-2.0468+0.0367*hhumir)+(-1.5955*pow(10,-6)*pow(hhumir,2));
		return n4;
	} //conversão humidade

	float convtempehum(int hhumir, int t, int hl){
		float n5=0;
		n5 = (t - 25) * (0.01 + 0.00008 * hhumir) + hl;
		return n5;
	} //conversão humidade/temperatura

	void espo(char* strr) {	
		for(int contador = 2; contador < 6; contador++){
    		strr[contador] = strr[contador + 1];
    		}
    } //retirar espaço
	
	
	
	
	
	

int main() {
	char* total = (char*) malloc (sizeof(char)*(70));
	char* quarto = (char*) malloc (sizeof(char)*(5));
	char* inf = (char*) malloc (sizeof(char)*(30));
	char* volt = (char*) malloc (sizeof(char)*(6));
	char* lvis = (char*) malloc (sizeof(char)*(6));
	char* linf = (char*) malloc (sizeof(char)*(6));
	char* humi = (char*) malloc (sizeof(char)*(6));
	char* temp = (char*) malloc (sizeof(char)*(6));
	int volthex, lvishex, linfhex, humihex, temphex;
	
	
	while(1){
	
	fgets(total, SIZE_OF_TOTAL ,stdin);
	
	
	strncpy(quarto, total+15,5);	//buscar o quarto
	strncpy(inf, total+30, 30);		//parte que interessa
	
	
	strncpy(volt,inf,6);			
	strncpy(lvis,inf+6,6);			
	strncpy(linf,inf+12,6);
	strncpy(temp,inf+18,6);
	strncpy(humi,inf+24,6);
	
	
	espo(temp);
	espo(volt);
	espo(linf);
	espo(humi);
	espo(lvis);
	
	volthex = (int)strtol(volt, NULL, 16);	//
	lvishex = (int)strtol(lvis, NULL, 16);	//
	linfhex = (int)strtol(linf, NULL, 16);	// Passa para decimal
	temphex = (int)strtol(temp, NULL, 16);	//
	humihex = (int)strtol(humi, NULL, 16);	//
	
	
	

	
	
	//debug
	printf("total: %s\n", total);
	printf("Quarto: %s\n", quarto);	
	printf("inf: %s\n", inf);
	printf("volt: %s\n", volt);
	printf("lv: %s\n", lvis);
	printf("li:%s\n", linf);
	printf("temp:%s\n", temp);
	printf("humt:%s\n", humi);
	printf("tem hex:%d\n", volthex);
	printf("lvishex:%d\n", lvishex);	
	printf("linfhex:%d\n", linfhex);	
	printf("temphex:%d\n", temphex);
	printf("humihex:%d\n", humihex);
	printf("volt dec:%.2f\n", convv(volthex));
	printf("temp dec:%.2f\n", convt(temphex));
	printf("lvis dec:%.2f\n", convlv(lvishex));
	printf("linf dec:%.2f\n", convli(linfhex));
	printf("humi dec:%.2f\n", convhumir(humihex));
	printf("humi re dec: %.2f\n", convtempehum(humihex, convt(temphex), convhumir(humihex)));

}



}

