#ifndef gift_h
#define gift_h
using namespace std;
class gift{
	public:
		char * name = (char*)(malloc(10  * sizeof(char)));
		int price=0;
		int value=0;
		int luxury_rating=0;
		int utility_value=0;
		int utility_class=0;
		void make_gift(char * n,int p,int v,int lr,int uv,int uc){
			strcpy(name,n);
			price = p;
			value = v;
			luxury_rating = lr;
			utility_value = uv;
			utility_class = uc;
		}
};
#endif
