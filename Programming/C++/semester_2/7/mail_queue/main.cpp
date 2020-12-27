# include "MailQueue.cpp"
void main()
{
	Mail_queue of;
	//setlocale(LC_ALL,"Russian");
   
	while(true)
	{
	cout<< "choose option: \n";
	cout<<"1 - read imformation from a file \n";
	cout<<"2 - output all information \n";
	cout<<"3 - add element \n";
	cout<<"4 - selecting the item with the highest priority and then deleting it \n";
	cout<<"5 - selection of the element with the longest informational part \n";
	cout<<"0 - exit \n" << endl;
     int i;
	cin>>i;
	switch(i)
	{
	case 1: of.read_from_file("file.txt");
		break;
	case 2: of.print(cout);
		break;
	case 3: of.add(cout,cin);
		break;
	case 4: of.chose_1(cout);
		break;
	case 5: of.chose_2(cout);
		break;
	case 0: return;

	}
	}
	system ("pause");
}