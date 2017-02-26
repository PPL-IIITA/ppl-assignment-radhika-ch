#include<bits/stdc++.h>
#include"boy.h"
#include"girl.h"
#include"gift.h"
#include"generate_boy.h"
#include"couple.h"
using namespace std;
vector <boy> vb;
vector <girl> vg;
vector <gift> vgift;

int maximum(vector<boy>&v,int c,girl v1)
{
	int max;
	for(int i=0;i<20;i++)
	{
		if(v[i].status == 0)
		{
			max = i;
			break;
		}
	}
	int flag;
	if(c == 0){
		flag = 0;
		for(int x=0;x<20;x++){
			if(v[x].status == 0){
				if(v[x].attractiveness > v[max].attractiveness && v[x].budget >= v1.maintenance && v[x].req >= v1.at_girl){
					max = x;
					flag = 1;
				}
			}
		}
		if(flag == 1){
			return max;
		}
		else
		{
			return 30;
		}
	}
	else if(c == 2){
		flag = 0;
		for(int x=0;x<20;x++){
			if(v[x].status == 0){
				if(v[x].intelligence > v[max].intelligence && v[x].budget >= v1.maintenance && v[x].req >= v1.at_girl){
					max = x;
					flag = 1;
				}
			}
		}
		if(flag == 1){
			return max;
		}
		else
		{
			return 30;
		}
	}
	else if(c == 1){
		flag = 0;
		for(int x=0;x<20;x++){
			if(v[x].status == 0){
				if(v[x].budget > v[max].budget && v[x].budget >= v1.maintenance && v[x].req >= v1.at_girl){
					max = x;
					flag = 1;
				}
			}
		}
		if(flag == 1){
			return max;
		}
		else
		{
			return 30;
		}
	}
}//cool
int cmp(gift a,gift b){
	if(a.price > b.price){
		return 1;
	}
	else{
		return 0;
	}
}	


vector <couple> vcouple; 
void form_couple(){
			char * s = (char*)malloc(10 * sizeof(char));
		
			
			
			FILE *fp1 = fopen("boys.txt","r");
			FILE * fp2 = fopen("girls.txt","r");
			int a,r,b,i,m,t,c,status,l;
			for(int y=0;y<20;y++)
			{
				fscanf(fp1,"%s %d %d %d %d %d %d",s,&a,&r,&b,&i,&status,&l);
				boy b1;
				b1.make_boy(s,a,r,b,i,status,l);
				vb.push_back(b1);
			}
		
		
			for(int y=0;y<10;y++)
			{
				fscanf(fp2,"%s %d %d %d %d %d %d %d ",s,&a,&m,&i,&status,&t,&c,&l);
				girl g1;
				g1.make_girl(s,a,m,i,status,t,c,l);
				vg.push_back(g1);
			}		
			FILE *fp5 = fopen("gifts.txt","r");
			int p=0,v=0,lr=0,uv=0,uc=0;
			for(int y=0;y<20;y++)
			{
				fscanf(fp5,"%s %d %d %d %d %d ",s,&p,&v,&lr,&uv,&uc);
			//	cout<<s<<" "<<p<<" "<<v<<" "<<lr<<" "<<uv<<" "<<uc<<endl;
				gift gift1;
				gift1.make_gift(s,p,v,lr,uv,uc);
				vgift.push_back(gift1);
			}	
			//check
		//	for(int x=0;x<10;x++){
		//		cout<<vgift[x].price<<endl;
		//	}
			FILE * fp3 = fopen("couples.txt","w");
			for(int x=0;x<10;x++){
				int z,val=0,total_price = 0;
				if(vg[x].status == 0){
					if(vg[x].type == 0){
						z = maximum(vb,0,vg[x]);
					//	cout<<z<<endl;
					//	cout<<vb[z].name<<endl;
						//cout<<z<<endl;
						int h,c;
						if(z != 30){
							couple c1(z,x,h,c);
							vcouple.push_back(c1);
						}
					//	cout<<vcouple[x].him<<endl;
					//	vcouple[x].him = z;
					//	cout<<"JLJ"<<endl;
						//cout<<z<<endl;
					//	vcouple[x].her = x;
						vb[z].status = 1;
						if(z != 30){
							fprintf(fp3,"launda%d is dating laundi%d\n",z,x);
							
							vg[x].status = 1;
						}
					}
					
					else if(vg[x].type == 1){
							 z = maximum(vb,1,vg[x]);
						//	cout<<z<<endl;
						//	cout<<vb[z].name<<endl;
						//	cout<<z<<endl;
							int h,c;
							if(z != 30){
							couple c1(z,x,h,c);
							vcouple.push_back(c1);
						}
					//		cout<<vcouple[x].him<<endl;
						//	cout<<"kjhgfdgh"<<endl;
						//	cout<<z<<endl;
							vb[z].status = 1;
							if(z!= 30){
								fprintf(fp3,"launda%d is dating laundi%d\n",z,x);
								//cout<<z<<endl;
								vg[x].status = 1;
							}
						}
					
					else{
							 z = maximum(vb,2,vg[x]);
						//	cout<<z<<endl;
						//	cout<<vb[z].name<<endl;
						//	cout<<z<<endl;
							int h,c;
							if(z != 30){
							couple c1(z,x,h,c);
							vcouple.push_back(c1);
						}
						//	cout<<vcouple[x].him<<endl;
						//	cout<<"Akjhghj"<<endl;
						//	cout<<z<<endl;
							vb[z].status = 1;
							if(z != 30){
								fprintf(fp3,"launda%d is dating laundi%d\n",z,x);
								//cout<<z<<endl;
								vg[x].status = 1;
							}
					}
				//	cout<<z<<endl;
					if(vb[z].legend == 0){
						int i=0;
						while(1){
							total_price = total_price + vgift[i].price;	
							if(total_price < vg[z].maintenance){
								i++;
							}
							else{
								break;
							}
							vg[z].gift_price = total_price;
						} 
						
					}
					if(vb[z].legend == 1){
						int i=0;
						while(1){
							total_price = total_price + vgift[i].price;	
							val = val + vgift[i].value;
							if(total_price < vb[z].budget){
								i++;
							}
							else{
								break;
							}
							vg[z].gift_price = total_price;
							vg[z].value = val;
						//	cout<<vg[z].value<<endl;
						} 
					}
					if(vb[z].legend == 2){
						int i=0;
						while(1){
							total_price = total_price + vgift[i].price;	
							if(total_price < vg[z].maintenance){
								i++;
							}
							else{
								break;
							}
							vg[z].gift_price = total_price;
						} 
				
					}
					
				}
		
			}
			
			fclose(fp1);
			fclose(fp2);
			fclose(fp3);
			fclose(fp5);
	}

int main(){
	int a,i,b,r,k,m,t,c,l,h,co,gfkb;
	cin>>gfkb;
	generate_boy  g1;
	g1.create(a,i,b,r,k,m,t,c,0,l);
	form_couple();
	sort(vgift.begin(),vgift.end(),cmp);
	for(int x=0;x<vcouple.size();x++){
		couple c1(vcouple[x].him,vcouple[x].her,h,co);
		//cout<<"launda"<<vcouple[x].him<<" "<<"is dating "<<"laundi "<<vcouple[x].her<<"    ";
		c1.natak(vgift,vb,vg);
	
	//	cout<<vcouple[x].her<<endl;
	//	cout<<vcouple[x].couple_happiness<<endl;
		
	}
		for(int z=0;z<gfkb;z++)
		{
			cout<<"launda"<<vcouple[z].him<<" "<<"laundi"<<vcouple[z].her<<endl;
		}
		cout<<endl;
		for(int z=gfkb-1;z>=0;z--)
		{
			cout<<"launda"<<vcouple[z].him<<" "<<"laundi"<<vcouple[z].her<<endl;	
		}
		
}

