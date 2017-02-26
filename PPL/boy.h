#ifndef boy_h
#define boy_h
using namespace std;
class boy{
	public:
		char *name= (char*)(malloc(10 * sizeof(char)));
		int attractiveness;
		int req;
		int budget;
		int intelligence;
		int status;
		int legend;
		int happiness;
		void make_boy(char* n,int a, int r,int b,int i,int s,int l){
			strcpy(name, n);
			attractiveness = a;
			req = r;
			budget = b;
			intelligence = i;
			status = s;
			legend = l;
		}
		void set_happiness(){
		}
};
#endif
