awk ' BEGIN{
	while(1){
		print("1.Ascensing")
		print("2.Descending")
		print("3.exit")
		print("enter choice: ")
		getline ch
		if(ch==3) break
		print("enter number of data: ")
		getline n
		for(i=0; i<n; i++){
			getline a[i]
		}
		for(i=0;i<n; i++){
			for(j=0;j<n-1;j++){
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
				for(i=0; i<n; i++){
					print(a[i])
				}
					break
			case 2:
				print("Descending order: ")
				for(i=n-1; i>=0; i--){
					print(a[i])
				}
					break
		}
	}
}'
