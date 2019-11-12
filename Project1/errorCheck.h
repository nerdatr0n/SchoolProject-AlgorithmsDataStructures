//
// Bachelor of Software Engineering
// Media Design School
// Auckland
// New Zealand
//
// (c) 2019 Media Design School
//
// File Name   : errorCheck.h
// Description : Contains all the error checks
// Author      : Andrew Barnes and David Haverland
// Mail        : andrew.bar8456@mediadesign.school.nz and david.hav8466@mediadesign.school.nz
//


bool CheckNodeInputErrors(string _strNodeInput)
{
	if (_strNodeInput.front() == ',' or _strNodeInput.back() == ',')
	{
		// Failed check
		return false;
	}

	for (int i = 0; i < _strNodeInput.size() - 1; i++)
	{
		if (_strNodeInput.at(i) == ',' and _strNodeInput.at(i + 1) == ',')
		{
			// Failed check
			return false;
		}
	}




	// removes spaces
	string::iterator end_pos = remove(_strNodeInput.begin(), _strNodeInput.end(), ' ');
	_strNodeInput.erase(end_pos, _strNodeInput.end());




	std::vector<string>::iterator it;
	string strAllStringsSeperate;
	vector<string> strings;
	strings.push_back(strAllStringsSeperate);

	std::string delimiter = ",";


	size_t pos = 0;

	string token;

	while ((pos = _strNodeInput.find(delimiter)) != string::npos) {

		token = _strNodeInput.substr(0, pos);

		_strNodeInput.erase(0, pos + delimiter.length());

		// Finds the meme i put in
		it = find(strings.begin(), strings.end(), token);
		if (it != strings.end())
		{
			return false;
		}
		else
		{
			strings.push_back(token);
		}
	}
	it = find(strings.begin(), strings.end(), _strNodeInput);
	if (it != strings.end())
	{
		return false;
	}
	else
	{
		strings.push_back(_strNodeInput);
	}

	// Passed check
	return true;
}


bool CheckForDigits(const string &str)
{
	return str.find_first_not_of("0123456789") == string::npos;
}


bool CheckEdgeAmountErrors(string _strEdgeAmount)
{
	if (!CheckForDigits(_strEdgeAmount))
	{
		// Failed check
		return false;
	}

	int iEdgeAmount = stoi(_strEdgeAmount);

	if (iEdgeAmount > 0 and iEdgeAmount < 100)
	{
		// Passed check
		return true;
	}
	// Failed check
	return false;

}

bool CheckEdgeErrors(string _strEdge, CGraph* _graph)
{
	// removes spaces
	string::iterator end_pos = remove(_strEdge.begin(), _strEdge.end(), ' ');
	_strEdge.erase(end_pos, _strEdge.end());

	if (count(_strEdge.begin(), _strEdge.end(), ',') != 1)
	{
		// Failed check
		return false;
	}

	std::string delimiter = ",";
	string token;
	size_t pos = 0;


	while ((pos = _strEdge.find(delimiter)) != string::npos) 
	{

		token = _strEdge.substr(0, pos);

		_strEdge.erase(0, pos + delimiter.length());

		token;



	}

	if (token == _strEdge)
	{
		// Failed check
		return false;
	}

	if (_graph->NodeNameToNumber(token) == -1 or _graph->NodeNameToNumber(_strEdge) == -1)
	{
		// Failed check
		return false;
	}


	// Passed check
	return true;
}



bool CheckStringCoords(string _strCoords)
{
	// removes spaces
	string::iterator end_pos = remove(_strCoords.begin(), _strCoords.end(), ' ');
	_strCoords.erase(end_pos, _strCoords.end());

	if (count(_strCoords.begin(), _strCoords.end(), ',') != 1)
	{
		// Failed check
		return false;
	}

	std::string delimiter = ",";
	string token;
	size_t pos = 0;

	string _strCoordy;

	while ((pos = _strCoords.find(delimiter)) != string::npos)
	{
		_strCoordy = _strCoords.substr(0, pos);

		_strCoords.erase(0, pos + delimiter.length());
	}


	int iCoordX = stoi(_strCoords);
	int iCoordY = stoi(_strCoordy);

	if (iCoordX > 9 || iCoordX < 0)
	{
		// Failed check
		return false;
	}
	if (iCoordY > 9 || iCoordY < 0)
	{
		// Failed check
		return false;
	}


	// Passed check
	return true;
}


