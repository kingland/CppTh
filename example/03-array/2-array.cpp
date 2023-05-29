
int main(){
	int ctarr[3]; // allocate on stack
	
	int * rtarr = new int[3]; // allocate on heap	
	delete [] rtarr; //deallocate on heap
}