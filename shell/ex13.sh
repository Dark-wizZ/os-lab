awk 'BEGIN {
	while(1){
		print("1.Ascending")
		print("2.Descending")
		print("3.Exit")
		print("Enter choice")
		getline ch
		if (ch==3) break
		print("Enter no of data")
		getline n
		print("enter elements: ")
		for(i=0; i<n; i++){
			getline a[i]
		}
		for(i=0; i<n-1; i++){
			for(j=0; j<n-i-1; j++){
				if(a[j]>a[j+1]){	
					temp=a[j]
					a[j]=a[j+1]
					a[j+1]=temp
				}	
			}
		}
		switch(ch){
			case 1:
				print("Ascending order: ")
				for(i=0; i<n; i++)
				print(a[i])
				break
			case 2:
				print("Descending order: ")
				for(i=n-1; i>=0; i--)
				print(a[i])
				break
		}
	}
}' 
