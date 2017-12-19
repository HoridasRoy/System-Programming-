#include<stdio.h>

int main()
{
	
	int log_mem,frame_size,offset,log_address,phy_address,page_no,frame_no,page_frame[100],arr_size,i;
	
	printf("Logical Memory Size: ");
	scanf("%d",&log_mem);	
	printf("Block Size: ");
	scanf("%d",&frame_size);
	printf("Logical Address: ");
	scanf("%d",&log_address);

	page_no = log_address/frame_size;

	offset = log_address - (page_no*frame_size);

	arr_size = log_mem/frame_size;

	for (i=0; i<arr_size; i++)
	{
		page_frame[i] = i+2;
	}

	for (i=0; i<arr_size; i++)
	{
		if(page_no == i)
			frame_no = page_frame[i];
	}
	
	phy_address = (frame_no*frame_size) + offset;

	printf("Physical Address: \n");
	printf("%d",phy_address);
	

	return 0;
}