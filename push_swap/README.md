*This project has been created as part of the 42 curriculum by mgiraldi and mojonker*

Description:
		
		Push swap is a project with the goal of sorting random set of integers on a stack in order. The restrictions of this project were to made so we had acess to 2 stacks and a set of commads we were allowed to use so the initial data set of integers get sorted in order. 
		For this project we had to develop 4 different modes, of which 3 of them were meant to be algorithms of O(n^2) complexity, named simple, (O(n√n)) complexity, named medium and a O(n log n), named complex. The 4th mode 
	is named adaptive, which selects which algorithm out of the previous 3 to use based on the computed disorder of the initial stack. On top of that we also develop a	bench mode, that keeps track of each used operation, the total number of operations used and which mode was used.

		For the O(n^2) algorithm we decided to use the selection sort method, which simply finds the biggest number in stack A and pushes it to stack B until stack A is
	empty then it all gets pushed back from B to A in order until stack B is empty.

		For the (O(n√n)) algorithm we decided for a chunk sort approach, in which we push numbers from stack A to B, pre sorting them by chunks, in which we decided to use 1.6 times the square root of the size of our stack, which seemed to perform the best as a general chunk size selection. For this algorithm we had to index our numbers	in order to properly chunk them in a consisent interval, then we push numbers from those intervals to B until we pushed all the numbers from that interval to B, then we move to the next chunk and repeat the process until stack A is empty is B has all the elements pre sorted to be pushed back to A in order.

		For O(n log n) algorithm we used a radix method in which we convert all the indexes of our stack into binary numbers, find the biggest number of digits we have then sort them in order in our stack B based on the number of digits to finally push them back to A in order.

		On top of those 3 modes adaptive has a few extra functionalities that allows it to sort stacks of 3, 4 and 5 numbers since a stack of 3 numbers will always take at maxium 2 operations to sort, a stack of 4 and 5 numbers will also use that form of sorting on adaptive since pushing 1/2 numbers of those stacks wil make it a 3 stack of integers and pushing those numbers back into A will take a small amount of operations.

		For our stack we used a type struct to hold our stack A, B, its sizes and its initial disorder. Both stacks A and B were made as 2D arrays, where the first dimension had the purpose of holding the value and the second dimension holds the index value of each number in a ranking system from 0 to the number of integers - 1 our stack have.
			Bench mode also has its on type struct with an array of integers that keeps track of the number of each operation called then adds them up for the total number of operations.

Instructions:

		Run make to compile the functions into push_swap. To run the push_swap file in forced simple mode run using push_swap --simple, to run in forced medium mode run using push_swap --medium, to run in forced complex mode run using push_swap --complex and to run in forced adaptive mode use push_swap --adaptive, if no simple, medium, complex or adaptive flag is added the program will default to adaptive. Another flag that can be added is --bench which will display the bench mode on stderr.
	
		The program can take either a string of numbers as its arguments
	**example: ./push_swap --bench "10 8 15 0 -15"**
	or any number as of numbers after the program name and flags 
	*example: ./push_swap --bench --adaptive 20 16 30 0 -30**

Resourses:

	For the theory of radix sorting:
		https://www.geeksforgeeks.org/dsa/radix-sort/
	For the theory of chunk sorting:
		https://satyadeepmaheshwari.medium.com/sorting-large-datasets-with-limited-memory-the-chunked-merge-sort-approach-318275275c81
	Also both libraries made from previous projects were used:
		ft_libft: https://github.com/MatheusGBi/Codam_Core/tree/78e8775a912dbd0518563bce13f067fe802dc2f5/libft
		ft_printf: https://github.com/MatheusGBi/Codam_Core/tree/78e8775a912dbd0518563bce13f067fe802dc2f5/ft_printf