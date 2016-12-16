#ifndef __CUTROD__H__
#define __CUTROD__H__

void bottom_up_cut_rod(int p[],int n,int* rs){
	for(int j=1;j<=n;j++){
		int q = INT_MIN;
		for(int i=1;i<=j;i++){
			if(q < p[i]+rs[j-i]){
				q = p[i]+rs[j-i];
				rs[j+n+1] = i;
			}
		}
		rs[j] = q;
	}
}



#endif