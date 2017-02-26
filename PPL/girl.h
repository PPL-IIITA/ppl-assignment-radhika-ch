#ifndef girl_h
#define girl_h
using namespace std;
class girl
{
	public:
		char *name= (char*)(malloc(10 * sizeof(char)));
		int at_girl;
		int maintenance;
		int intelligence;
		int status;
		int type;
		int criteria;
		int legend;
		int gift_price;
		int value;
		int happiness;
		void make_girl(char* n,int a,int m,int i,int s,int t,int c,int l){
			s = 0;
			strcpy(name,n);
			at_girl = a;
			maintenance = m;
			intelligence = i;
			status = s;
			type = t;
			criteria = c;
			legend = l;
		}
		void set_happiness(){
		}
};
#endif
