#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int main()
{
	
int x,j,omada1[18][18],temp2,dk[18],xwritikotita,dunamikotita,omada2[18][18],i,sum[18],temp,ku[18],kk[18],temp5,temp6,xwrit[18],
dun[18],p_f2[8],on[4],f4[4],tel[4],ol[4],mf[2],final[2];																					//////dhlwsh metablhtwn//////
char onoma[100], xwra[100],apotelesma[18][18],temp1[200],on_omada[18],temp3[200],temp4[200],ono[18][100],xwra1[18][100];
			
FILE *fp_teams,*fp_res;
fp_teams = fopen("teams.txt", "r");					//////anoigma apo to onoma tou arxeiou//////
if(fp_teams == NULL)
{
    printf("Error: File can’t be loaded\n");		//////periptwsh pou to arxeio den uparxei//////
	return 0;
}
for(i=0;i<18;i++)
{
    fscanf(fp_teams,"%s%s%d%d",onoma,xwra,&xwritikotita,&dunamikotita);				//////sarwsh twn stoixeiwn tou arxeiou wste na diabastoun apo to programma//////
    strcpy(ono[i], onoma);
    strcpy(xwra1[i],xwra);			//////Metafora twn stoixeiwn tou arxeiou se pinaka//////
    xwrit[i]=xwritikotita;
    dun[i]=dunamikotita;
}
fclose(fp_teams);

srand(time(NULL));       			//////sunartish rand wste na dinei times apo thn arxh ths C++//////                              

for(i=0;i<18;i++)
{					
	ku[i]=0;						//////arxikopoihsh athroismatos kalathiwn entos-ektos////////
	kk[i]=0;
}
    
for(i=0;i<18;i++)    				//////ghpedouxos//////
{
	for(j=0;j<18;j++)  		 		//////filoxenoumenos//////
	{
		if (i!=j)  					//////xwris thn kuria diagwnio wste h kathe omada na mhn paizei me ton eauto ths//////
		{			
		if(xwra1[i]==xwra1[j])		//////periptwsh paixnidiou duo omadwn apo thn idia xwra wste na mhn uparxei bonus//////
			break;																	
			if(xwrit[i]>=10 && xwrit[i]<=15)								
			{																						
				omada1[i][j]= 50 + rand( ) % (1 + dun[j]/2);							
				omada2[i][j]= 50 + rand( ) % (1 + dun[i]/2)+3;					
				kk[i]=kk[i]+omada1[i][j];															
				ku[i]=ku[i]+omada2[i][j];															
			}																		
			else if (xwrit[i]>15)														
			{																		
				omada1[i][j]= 50 + rand( ) % (1 + dun[j]/2);				//////dhmiourgia pontwn entos ektos me bash thn xwritikothta//////	
				omada2[i][j]= 50 + rand( ) % (1 + dun[i]/2)+5;						
				kk[i]=kk[i]+omada1[i][j];									//////upologismos kalathiwn uper kai kata ths kathe omadas//////						
				ku[i]=ku[i]+omada2[i][j];															
			}																						
			else																					
			{																				
				omada1[i][j]= 50 + rand( ) % (1 + dun[j]/2);							
				omada2[i][j]= 50 + rand( ) % (1 + dun[i]/2);							
				kk[i]=kk[i]+omada1[i][j];															
				ku[i]=ku[i]+omada2[i][j];															
			}																						
			if(omada1[i][j]==omada2[i][j])			
			{											
				x=1 + rand( ) % 2 ;					
				if (x==1)							
				omada1[i][j]=omada1[i][j]+1;					//////periptwsh isobathmias//////
				else								
				omada2[i][j]=omada2[i][j]+1;		
			}											
		if(omada1[i][j]>omada2[i][j])									
			apotelesma[i][j]='W';											
		else								       				//////dhmiourgia pinaka W-L gia eukolia//////
			apotelesma[i][j]='L';				   
		}
		else										
		{											
			omada1[i][j]= 10;						
			omada2[i][j]= 10;											
			apotelesma[i][j]=' ';					
		}														
	}																					
}
													
for(i=0;i<18;i++)
dk[i]= ku[i]-kk[i];									//////upologismos diaforas kalathiwn gia kathe omada//////

for(i=0;i<18;i++)												
sum[i]=0;											//////arxikopoihsh sum////////
					
for(i=0;i<18;i++)							
{											
	for(j=0;j<18;j++)						
	{										
		if(i!=j)							
		{									
			if( apotelesma[i][j]=='W');									
			sum[i]=sum[i]+2; 						//////upologismos bathmologias//////						
			if (apotelesma[i][j]=='L')										
			sum[i]=sum[i]+1;										
		}									
	}										
}											

for(i = 1; i < 18; i++)																				
{																									
	for(j = 17; j >= i; j--)																		
	{																								
		if(sum[j] > sum[j-1])						//////sugkrish bathmwn//////												
   		{																				
			temp = sum[j];     																		
 		   	sum[j] = sum[j-1];            			//////taxinomhsh bathmwn//////									
 			sum[j-1] = temp;																				
			 																										
   			temp2= dk[j];																						
			dk[j]=dk[j-1];							//////taxinomhsh pinaka diaforas kalathiwn sumfona me thn bathmologia//////							
			dk[j-1]=temp2;																						
																				
 	   		strcpy(temp1, ono[j]);																	
  		  	strcpy(ono[j],ono[j-1]);  				//////taxinomhsh onomatwn me bash th bathmologia//////	
  			strcpy(ono[j-1],temp1);																
																																																
			strcpy(temp4, xwra1[j]);																	
			strcpy(xwra1[j], xwra1[j-1]);			//////taxinomhsh xwras ths kathe omadas me bash th bathmologia//////														
			strcpy(xwra1[j-1], temp4);																					
																															
			temp5= xwrit[j];																			
			xwrit[j]= xwrit[j-1];					//////taxinomhsh xwritikothtas ghpedou ths kathe omadas me bash th bathmologia//////				
			xwrit[j-1]=temp5;																		
																												
			temp6= dun[j];															
			dun[j]= dun[j-1];						//////taxinomhsh dunamikothtas ths kathe omadas me bash th bathmologia//////						
			dun[j-1]= temp6;																	
		}																										
		else if (sum[j] == sum[j-1]) 				//////periptwsh isobathmias sthn bathmologia//////										
		{																												
			if (dk[j] > dk[j-1])					//////sugkrish diaforas kalathiwn//////											
   			{																											
   				temp2= dk[j];																								
				dk[j]=dk[j-1];						//////taxinomish sumfwna me thn diafora kalathiwn//////						
				dk[j-1]=temp2;																				
			}																						
		}																								
	}																								
}	
printf("=======================================|\n");																										
printf("WELCOME TO VIRTUAL EUROLEAGUE 2019-2020|");
printf("\n=======================================|\n");
printf("\n===========*PHASE 1 MARKING*===========|\n\n");
printf("  P.   TEAM\n\n");
for(i=0;i<18;i++)																									
printf("  %d  %s\n",sum[i],ono[i]);								//////ektupwsh ths bathmologias//////																				
printf("\n============================|\n");
printf("QUALIFIED TO THE NEXT PHASE:|");
printf("\n============================|\n\n");
for(i=0;i<8;i++)
printf("*%s\n",ono[i]);											//////ektupwsh omadwn pou perasan sthn epomenh fash//////

for(i=0;i<8;i++)	
{
	if(xwra1[i]==xwra1[j])										//////periptwsh paixnidiou duo omadwn apo thn idia xwra wste na mhn uparxei bonus//////
	break;
	if(xwrit[i]>=10 && xwrit[i]<=15)								
	p_f2[i]=50 + rand( ) % (1 + dun[i]/2)+3;																																						
	else if (xwrit[i]>15)																																				
	p_f2[i]=50 + rand( ) % (1 + dun[i]/2)+5;					//////upologismos pontwn ton prokrithentwn omadwn//////																																
	else																																											
	p_f2[i]=50 + rand( ) % (1 + dun[i]/2);																
}

for(i=0;i<4;i++)
{
	for(j=7;j>0;j--)
	{
		if(i+j == 7)
		{
			if(p_f2[i]>p_f2[j])							//////sugkrish score twn prokrithentwn omadwn//////		
			on[i]=i;
			else if (p_f2[i]<p_f2[j])
			on[i]=j;
			else										//////periptwsh isobathmias//////
			{
				x=1 + rand( ) % 2 ;
				if (x==1)
				on[i]=i;	
				else
				on[i]=j;												
			}
		}
	}
}	
printf("\n=====================|\n");
printf("QUALIFIED TO FINAL 4:|");
printf("\n=====================|\n\n");	
for(i=0;i<4;i++)
printf("*%s\n",ono[on[i]]);								//////ektupwsh twn omadwn pou prokrithikan sto final 4//////
	
for(i=0;i<4;i++)																						
f4[i]=50 + rand( ) % (1 + dun[on[i]]/2);				//////upologismos kalathiwn ths kathe omadas sto final 4//////

for(i=0;i<2;i++)
{
	for(j=3;j>0;j--)
	{
		if(i+j==3)
		{
			if(f4[i]>=f4[j])  							//////sugkrish score tou final 4//////
			{
				tel[i]=on[i];							//////nikhtes//////
				ol[i]=on[j];							//////htthmenoi//////
			}
			else if(f4[i]<f4[j])
			{
				tel[i]=on[j];
				ol[i]=on[i];
			}
			else
			{
				x=1 + rand( ) % 2 ;						//////periptwsh isobathmias//////
				if (x==1)
				{
					tel[i]=on[i];
					ol[i]=on[j];	
				}
				else
				{
					tel[i]=on[j];
					ol[i]=on[i];
				}		
			}
		}
	}
}
printf("\n========================|\n");
printf("QUALIFIED TO MINI FINAL:|");
printf("\n========================|\n\n");	
for(i=0;i<2;i++)										//////ektupwsh twn omadwn pou prokrithhkan ston mikro teliko//////
printf("*%s\n",ono[ol[i]]);								

for(i=0;i<2;i++)
mf[i]=50 + rand( ) % (1 + dun[ol[i+1]]/2);				//////upologismos kalathiwn ths kathe omadas ston mikro teliko//////
		
for(i=0;i<2;i++)
final[i]=50 + rand( ) % (1 + dun[tel[i]]/2);					//////upologismos kalathiwn ths kathe omadas ston teliko//////	
printf("\n===================|\n");
printf("QUALIFIED TO FINAL:|");
printf("\n===================|\n\n");	
for(i=0;i<2;i++)
printf("*%s\n",ono[tel[i]]);										//////ektupwsh twn omadwn pou prokrithikan ston teliko//////
printf("\n\n");
for(i=0;i<1;i++)										
{
	if(mf[i]>mf[i+1])												//////sugkrish score tou mikrou telikou//////
	printf("***MINI FINAL WINNER***\n\n***%s***",ono[ol[i]]);
	else if (mf[i]<mf[i+1])
	printf("***MINI FINAL WINNER***\n\n***%s***",ono[ol[i+1]]);
	else															//////periptwsh isobathmias//////
	{
		x=1 + rand( ) % 2 ;
		if (x==1)
		printf("***MINI FINAL WINNER***\n\n***%s***",ono[ol[i]]);			
		else
		printf("***MINI FINAL WINNER***\n\n***%s***",ono[ol[i+1]]);			
	}
}

printf("\n\n\n***EUROLEAGUE WINNER 2019-2020***\n\n");
for(i=0;i<1;i++)
{
	if(final[i]>final[i+1])										//////upologismos kalathiwn gia kathe omada tou telikou//////
	printf("***%s***",ono[tel[i]]);
	else if (final[i]<final[i+1])
	printf("***%s***",ono[tel[i+1]]);
	else
	{
		x=1 + rand( ) % 2 ;
		if (x==1)
		printf("***%s***",ono[tel[i]]);	
		else
		printf("***%s***",ono[tel[i+1]]);			
	}
}

fp_res = fopen("result.txt", "w");										//////eggrafh se arxeio me onoma result.txt//////
if(fp_res == NULL)
{
  	printf("Error: File_1 can’t be created\n");
   	return 0;
}
fprintf(fp_res,"========== VIRTUAL EUROLEAGUE 2019-2020 ==========\n\n");
fprintf(fp_res,"========== FHASE 1 ==========\n\n");
fprintf(fp_res,"FHASE 1 MARKING:\n\n");
fprintf(fp_res,"POS. P. TEAM.\n");
for(i=0;i<18;i++)
fprintf(fp_res,"%d.   %d %s\n",i+1,sum[i],ono[i]);						//////emfanish theshs == bathmwn == onomatwn omadwn sto arxeio//////
fprintf(fp_res,"\n\nFHASE 1 RESULTS:\n\n");
for(i=0;i<18;i++)
{
	for(j=0;j<18;j++)
	{
		if(i!=j)
		{
			fprintf(fp_res,"%s - %s : %d - %d\n",ono[i],ono[j],omada2[i][j],omada1[i][j]);   	//////emfanish apotelesmatwn ths fashs 1//////
		}
	}
	fprintf(fp_res,"\n");
}
fprintf(fp_res,"PHASE 1 RULES:\n");
fprintf(fp_res,"All teams have home and away matches.\n");
fprintf(fp_res,"Home teams have a bonus base on the seats of the stadium.\n");
fprintf(fp_res,"If faced teams from the same country there is no bonus.\n");
fprintf(fp_res,"WIN = 2 POINTS - LOSE = 1 POINT.\n");
fprintf(fp_res,"The first eight teams qualifies to the phase 2.\n");
fprintf(fp_res,"In case of a TIE the team with highest point difference qualifies.\n");
fprintf(fp_res,"\n\nQUALIFIED TO FHASE 2:\n\n");
for(i=0;i<8;i++)
fprintf(fp_res,"%s\n",ono[i]);									//////emfanish omadwn pou perasan sthn fash 2//////
fprintf(fp_res,"\n\n========== FHASE 2 ==========\n\n");
fprintf(fp_res,"FHASE 2 RESULTS:\n\n");
for(i=0;i<4;i++)
{
	for(j=7;j>0;j--)
	{			
		if(i+j == 7)
		fprintf(fp_res,"%s-%s : %d-%d\n",ono[i],ono[j],p_f2[i],p_f2[j]);			//////emfanish apotelesmatwn ths fashs 2//////
	}
}
fprintf(fp_res,"\nPHASE 2 RULES:\n");
fprintf(fp_res,"Knock out games.\n");
fprintf(fp_res,"Opponets are 1st-8th,2nd-7th,3rd-6th,4th-5th.\n");
fprintf(fp_res,"Home teams are the teams with the highest position\n");
fprintf(fp_res,"Home teams have a bonus base on the seats of their stadium.\n");
fprintf(fp_res,"If faced teams from the same country there is no bonus.\n");
fprintf(fp_res,"Winner teams qualified to final 4.\n");
fprintf(fp_res,"\n\nQUALIFIED TO FINAL 4 :\n\n");
for(i=0;i<4;i++)
fprintf(fp_res,"%s\n",ono[on[i]]);													//////emfanish omadwn pou prokrithikan sto final 4//////
fprintf(fp_res,"\n\n========== FINAL 4 ==========\n\n");
fprintf(fp_res,"FINAL 4 RESULTS:\n\n");
for(i=0;i<2;i++)
{
	for(j=3;j>0;j--)
	{
		if(i+j==3)
		fprintf(fp_res,"%s - %s : %d - %d\n",ono[on[i]],ono[on[j]],f4[i],f4[j]);  	//////emfanish apotelesmatwn tou final 4//////
	}
}
fprintf(fp_res,"\nFINAL 4 RULES:\n");
fprintf(fp_res,"Knock out games.\n");
fprintf(fp_res,"Opponets are 1st-8th vs 4th-5th, 2nd-7th vs 3rd-6th.\n");
fprintf(fp_res,"Games are in neutral stadiums.\n");
fprintf(fp_res,"Winner teams qualified to final.\n");
fprintf(fp_res,"Defeated teams qualified to mini final.\n");
fprintf(fp_res,"Final and mini final are knock out games in neutral stadiums.\n");
fprintf(fp_res,"\n\nQUALIFIED TO MINI FINAL:\n\n");
for(i=0;i<2;i++)
fprintf(fp_res,"%s\n",ono[ol[i]]);													//////emfanish omadwn pou prokrithikan ston mikro teliko//////
fprintf(fp_res,"\n\nQUALIFIED TO FINAL:\n\n");
for(i=0;i<2;i++)
fprintf(fp_res,"%s\n",ono[tel[i]]);													//////emfanish omadwn pou prokrithikan ston teliko//////
fprintf(fp_res,"\n\n========== MINI FINAL ==========\n\n");
fprintf(fp_res,"MINI FINAL RESULTS:\n\n");
for(i=0;i<1;i++)
fprintf(fp_res,"%s - %s : %d - %d\n",ono[ol[i]],ono[ol[i+1]],mf[i],mf[i+1]);		//////apotelesma mikrou telikou//////
fprintf(fp_res,"\n\n========== MINI FINAL WINNER ==========\n\n");
for(i=0;i<1;i++)
{
	if(mf[i]>mf[i+1])
	fprintf(fp_res,"***%s***",ono[ol[i]]);
	else if (mf[i]<mf[i+1])
	fprintf(fp_res,"***%s***",ono[ol[i+1]]);
	else
	{																				//////emfanish tou nikith tou mikrou telikou//////
		x=1 + rand( ) % 2 ;
		if (x==1)		
		fprintf(fp_res,"***%s***",ono[ol[i]]);			
		else
		fprintf(fp_res,"***%s***",ono[ol[i+1]]);			
	}
}
fprintf(fp_res,"\n\n========== FINAL ==========\n\n");
fprintf(fp_res,"FINAL RESULTS:\n\n");
for(i=0;i<1;i++)
fprintf(fp_res,"%s - %s : %d - %d\n",ono[tel[i]],ono[tel[i+1]],final[i],final[i+1]);  		//////apotelesma telikou//////
fprintf(fp_res,"\n\n========== FINAL WINNER ==========\n\n");
for(i=0;i<1;i++)
{
	if(final[i]>final[i+1])
	fprintf(fp_res,"***%s***",ono[tel[i]]);
	else if (final[i]<final[i+1])
	fprintf(fp_res,"***%s***",ono[tel[i+1]]);
	else
	{																					//////emfanish nikith euroligkas//////
		x=1 + rand( ) % 2 ;
		if (x==1)		
		fprintf(fp_res,"***%s***",ono[tel[i]]);			
		else		
		fprintf(fp_res,"***%s***",ono[tel[i+1]]);					
	}
}
fclose(fp_res);

return 0;
}
