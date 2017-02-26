#ifndef couple_h
#define couple_h
#include"gift.h"
#include"boy.h"
#include"girl.h"
using namespace std;
class couple{
	public:
		int him=0;
		int her=0;
		int his_happiness=0;
		int her_happiness=0;
		int couple_happiness;
		int compatibility=0;
		int total_price=0;
		couple(int bf,int gf,int h,int c){
			him = bf;
			her = gf;
			couple_happiness = h;
			compatibility = c;
		}
		void natak(vector<gift>&vgift,vector<boy>&vb,vector<girl>&vg)
		{
			
			if(vb[him].legend == 0){
				his_happiness = (abs(vg[her].gift_price - vb[him].budget));
			//	cout<<his_happiness<<endl;
				couple_happiness = his_happiness;
			//	vc.couple_happiness = couple_happiness;
			}
			else if(vb[him].legend == 1){
				his_happiness = (vg[her].gift_price + vg[her].gift_price);
				couple_happiness = his_happiness;
				//vc.couple_happiness = couple_happiness;
			//	cout<<vg[her].gift_price<<endl;
			//	cout<<vg[her].value<<endl;
			//	cout<<(vg[her].gift_price +  vg[her].value);
			//	cout<<his_happiness<<endl;
			}
			else{
				his_happiness = vg[her].intelligence;
				couple_happiness = his_happiness;
				//vc.couple_happiness = couple_happiness;
			//	cout<<his_happiness<<endl;
			}
		
			if(vg[her].legend == 0){
				int t = 0 , x = vg[her].gift_price + vg[her].value ;
	                while ( x ) { t++ ; x /= 10 ; }
	                her_happiness = t;
	                couple_happiness = couple_happiness + her_happiness;
	               //	vc.couple_happiness = couple_happiness;
	               // cout<<couple_happiness<<endl;
	              //  cout<<her_happiness<<endl;
			}
			else if(vg[her].legend == 1){
				her_happiness = his_happiness;
			//	cout<<her_happiness<<endl;
				couple_happiness = her_happiness + her_happiness;
				//vc.couple_happiness = couple_happiness;
				//cout<<couple_happiness<<endl;
			//	cout<<her_happiness<<endl;
			}
			else{
				her_happiness = vg[her].gift_price * vg[her].gift_price * vg[her].gift_price;
				couple_happiness = couple_happiness + her_happiness;
				//vc.couple_happiness = couple_happiness;
				//cout<<couple_happiness<<endl;
			//	cout<<her_happiness<<endl;
			}
			int max_happiness;
			if(couple_happiness > max_happiness){
				max_happiness = couple_happiness;
			}
			compatibility = abs((vb[him].budget - vg[her].maintenance) )+ (abs(vb[him].attractiveness - vg[her].at_girl)) + (abs(vb[him].intelligence) - vg[her].intelligence);
			//cout<<"Happiness-"<<couple_happiness<<" "<<"Compatibility-"<<compatibility<<"\n";
			
		}
};
#endif
