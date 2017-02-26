#ifndef generate_boy_h
#define generate_boy_h
using namespace std;
class  generate_boy{
	
	public:
		int  a;
		int m;
		int  i;
		int  b;
		int  r ;
		int type;
		int criteria;
		void create(int a,int i,int b,int r,int k,int m,int type,int criteria,int status,int l){
			FILE *fp1;
			fp1 = fopen("boys.txt","w");
			for(int x=0;x<20;x++){
				a = (rand()%10);
				i = (rand()%10);
				b = (rand()%10);
				r = (rand()%10);
				l = (rand()%3);
				status = 0;
				fprintf(fp1,"Launda%d  %d  %d  %d  %d %d %d\n",x,a,i,b,r,status,l);
			}
			fclose(fp1);
			FILE *fp2;
			fp2 = fopen("girls.txt","w");
			for(int x=0;x<10;x++){
				a = (rand()%10);
				i = (rand()%10);
				m = (rand()%10);
			    type = (rand()% 3);
				criteria = (rand()%3);
				status = 0;
				l = (rand()%3);
				fprintf(fp2,"Laundi%d %d %d %d %d %d %d %d\n",x,a,i,m,type,criteria,status,l);
			}		
			fclose(fp2);
				FILE * fp4 = fopen("gifts.txt","w");
				int number,price,value,luxury_rating,utility_value,utility_class;
				
				for(int x=0;x<20;x++)
				{
					number = (rand() % 3);
					price = (rand() % 10);
					value = (rand()%10);
					if(number == 0){
						luxury_rating=0;
						utility_value = 0;
						utility_class = 0;
					}
					else if(number == 1)
					{
						luxury_rating = (rand()%10) + 1;
						utility_value = 0;
						utility_class = 0;
					}
					else
					{
						luxury_rating = 0;
						utility_value = (rand()%10) + 1;
						utility_class = (rand()%10) + 1;
					}
					fprintf(fp4,"Gift%d   %d   %d   %d   %d   %d\n",x,price,value,luxury_rating,utility_value,utility_class);
				}
				fclose(fp4);
		}			
};
#endif
