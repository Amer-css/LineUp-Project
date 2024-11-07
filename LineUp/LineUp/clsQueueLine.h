#pragma once
#include<iostream>
#include <ctime>
#include"queue"
#include"stack"
#include <string>
#include"clsDate.h"

using namespace std;
class clsQueueLine
{
	short _TotalTickets = 0;
	short _AverageServeTime = 0;
	string _Prefix = "";
	
	
	class clsTicket
	{

		short _Number = 0;
		string _Prefix;
		string _TicketTime;
		short _WaitingClients = 0;
		short _AverageServeTime = 0;
		short _ExpectedServeTime = 0;
	

	public:
		clsTicket(string Prefix, short Number, short WaitingClients, short AverageServeTime)
		{
			_Number = Number;
			_Prefix = Prefix;
			_TicketTime = clsDate::GetSystemDateTimeString();
			_WaitingClients = WaitingClients;
			_AverageServeTime = AverageServeTime;

		}

		string Prefix()
		{
			return _Prefix;
		}

		short Number()
		{
			return _Number;
		}

		string FullNumber()
		{
			return _Prefix = to_string(_Number);
		}

		string TicketTime()
		{
			return _TicketTime;
		}

		short WaitingClients()
		{
			return _WaitingClients;
		}


		short ExpectedServeTime()
		{
			return _AverageServeTime * _WaitingClients;
		}

		void PrintA()
		{

			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << "A0" << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketTime;
			cout << "\n\t\t\t    Waiting Clients = " << _WaitingClients;
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";

		}
		void PrintB()
		{

			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << "B0" << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketTime;
			cout << "\n\t\t\t    Waiting Clients = " << _WaitingClients;
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";

		}

	};
	
public:

	queue<clsTicket>QueueLine;
	
	clsQueueLine(string Prefix, short AverageServeTime)
	{
		_Prefix = Prefix;
		_TotalTickets = 0;
		_AverageServeTime = AverageServeTime;
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(),
			_AverageServeTime);
		QueueLine.push(Ticket);

	}

	int WaitingClients()
	{
		return QueueLine.size();
	}

	string WhoIsNext()
	{
		if (QueueLine.empty())
			return "No Client Left";
		else
			return QueueLine.front().FullNumber();
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
			return false;
		else
			QueueLine.pop();
			return true;
	}

	short ServedCleints()
	{
		return _TotalTickets - WaitingClients();
	}


	void PrintInfo()
	{


		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix          = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedCleints();
		cout << "\n\t\t\t    Waiting Clients = " << WaitingClients(); ;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";
	}

	

	void PrintAllTicketA()
	{
		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		queue<clsTicket> TempQueueLien = QueueLine;


		while (!TempQueueLien.empty())
		{
			TempQueueLien.front().PrintA();
			TempQueueLien.pop();
		}

	}
	void PrintAllTicketB()
	{
		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";

		queue<clsTicket> TempQueueLien = QueueLine;


		while (!TempQueueLien.empty())
		{
			TempQueueLien.front().PrintB();
			TempQueueLien.pop();
		}

	}

};






	

