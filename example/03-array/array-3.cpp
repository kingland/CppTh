
class Point
{
    int x, y;
public:
    Point( int x=0, int y=0);
    //...
};

int main(){
	
	Point * t1 = new Point[4]; //array of object allocate on heap
	Point t1[4]; //array of object allocate on stack
	
	
	Point ** t2 = new Point*[ 4 ]; //array of pointer
	
	for(int i=0; i<4; ++i){
		t2[i] = new Point(0,0);
	}
	
	for(int i=0; i<4; ++i){
		cout<<*t2[ i ]<<endl;
	}
}