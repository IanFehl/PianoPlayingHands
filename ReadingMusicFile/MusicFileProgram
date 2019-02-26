#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <list>

using namespace std;

int main() {
	int tempo; // stores tempo value as integer
	string clef; // stores clef (treble or bass) as string
	string duration; // stores note duration as string
	string position; // stores note position as string
	string line; // used to parse through each line of text file
	string previousLine; // stores previous line of text file
	ifstream inFile; // input filestream
	ofstream outFile; // output filestream
	list <int> noteDurationsTreble1; // list of integers for all note durations
	list <int> noteDurationsTreble2; // list of integers for all note durations
	list <int> noteDurationsTreble3; // list of integers for all note durations
	list <int> noteDurationsBass1; // list of integers for all note durations
	list <int> noteDurationsBass2; // list of integers for all note durations
	list <int> noteDurationsBass3; // list of integers for all note durations
	list <string> notePositionsTreble1; // list of strings for all note positions for Treble clef
	list <string> notePositionsTreble2; // list of strings for all note positions for Treble clef
	list <string> notePositionsTreble3; // list of strings for all note positions for Treble clef
	list <string> notePositionsBass1; // list of strings for all note positions for Bass clef
	list <string> notePositionsBass2; // list of strings for all note positions for Bass clef
	list <string> notePositionsBass3; // list of strings for all note positions for Bass clef
	int counter = 0; // used for counter arrays
	list <int> counterArrayTreble1;
	list <int> counterArrayTreble2;
	list <int> counterArrayTreble3;
	list <int> counterArrayBass1;
	list <int> counterArrayBass2;
	list <int> counterArrayBass3;
	char comma; 
	string temp;
	int trebleCounter = 0;
	int bassCounter = 0;
	
	std::string::size_type findTempo;
	std::string::size_type findClef;
	std::string::size_type findDuration;
	std::string::size_type findPosition;
	std::string::size_type findWhole;
	std::string::size_type findHalf;
	std::string::size_type findQuarter;
	std::string::size_type findEighth;
	std::string::size_type findSixteenth;
	std::string::size_type findThirty;
	std::string::size_type findDotted;
	std::string::size_type findComma;
	std::string::size_type findSignature;
	std::string::size_type findRest;

	inFile.open("One_More_Light.nwctxt");
	outFile.open("OML_values.txt");

	if (inFile.is_open()) {
		while (getline(inFile, line, '|')) { // read values in between '|' symbols and output to text file
			findTempo = line.find("Tempo:"); // set findTempo equal to "Tempo:" to find tempo value in the text file
			findWhole = line.find("Whole"); // set findWhole equal to "Whole" to find whole notes in the text file
			findHalf = line.find("Half"); // set findHalf equal to "Half" to find half notes in the text file
			findQuarter = line.find("4th"); // set findQuarter equal to "4th" to find quarter notes in the text file
			findEighth = line.find("8th"); // set findEighth equal to "8th" to find eighth notes in the text file
			findSixteenth = line.find("16th"); // set findSixteenth equal to "16th" to find sixteenth notes in the text file
			findThirty = line.find("32nd"); // set findThirty equal to "32nd" to find thirty-secondth notes in the text file
			findClef = line.find("Type:"); // set findClef equal to "Type:" to find clef value in the text file
			findDuration = line.find("Dur:"); // set findDuration equal to "Dur:" to find note duration value in the text file
			findPosition = line.find("Pos:"); // set findPosition equal to "Pos:" to find note position value in the text file
			findDotted = line.find("Dotted"); // set findDotted equal to "Dotted" to find dotted notes in the text file
			findSignature = line.find("Signature:");
			findRest = previousLine.find("Rest");

			if (findTempo != string::npos) { // if findTempo is not at position 0 (invalid position)
				tempo = stoi(line.substr(findTempo + 6)); // convert all of the characters after the colon (located at position 6) into an integer and set
														  // tempo equal to that integer
			}

			if (findClef != string::npos) { // if findClef is not at position 0 (invalid position)
				clef = line.substr(findClef + 5);  // set clef equal to string of characters after colon
				if (clef == "Treble\n")  outFile << "trebleCounter: " << trebleCounter << endl; 
				else if (clef == "Bass\n") outFile << "bassCounter: " << bassCounter << endl; 
			}

			if (findSignature != string::npos) {
				if (previousLine == "Key") {
					outFile << "Clef: " << clef << "Signature: " << line.substr(findSignature + 10) << endl << endl;
				}
			}

			if (findDuration != string::npos) { // if findDuration is not at position 0 (invalid position)
				duration = line.substr(findDuration + 4); // set duration equal to string of characters after colon
				if (findWhole != string::npos) { // whole note
					if (findDotted != string::npos) {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(11); // 11 = Dotted Whole 
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(11);
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(11);
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(11);
							else if (bassCounter == 2) noteDurationsBass2.push_back(11);
							else if (bassCounter == 3) noteDurationsBass3.push_back(11);
						}
					}
					else {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(1);
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(1);
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(1);
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(1);
							else if (bassCounter == 2) noteDurationsBass2.push_back(1);
							else if (bassCounter == 3) noteDurationsBass3.push_back(1);
						}
					}
				}
				else if (findHalf != string::npos) { // half note
					if (findDotted != string::npos) {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(12); // 12 = Dotted Half 
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(12);
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(12); 
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(12);
							else if (bassCounter == 2) noteDurationsBass2.push_back(12);
							else if (bassCounter == 3) noteDurationsBass3.push_back(12); 
						}
					}
					else { 
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(2);
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(2);
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(2);
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(2);
							else if (bassCounter == 2) noteDurationsBass2.push_back(2);
							else if (bassCounter == 3) noteDurationsBass3.push_back(2);
						}
					}
				}
				else if (findQuarter != string::npos) {  // quarter note
					if (findDotted != string::npos) {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(13); // 13 = Dotted Quarter 
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(13);
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(13);
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(13);
							else if (bassCounter == 2) noteDurationsBass2.push_back(13);
							else if (bassCounter == 3) noteDurationsBass3.push_back(13);
						}
					}
					else {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(4); // add duration to end of the list
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(4); // add duration to end of the list
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(4); // add duration to end of the list
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(4); // add duration to end of the list
							else if (bassCounter == 2) noteDurationsBass2.push_back(4); // add duration to end of the list
							else if (bassCounter == 3) noteDurationsBass3.push_back(4); // add duration to end of the list
						}
					}
				}
				else if (findEighth != string::npos) { // eighth note
					if (findDotted != string::npos) {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(14); // 14 = Dotted Eighth 
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(14);
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(14);
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(14);
							else if (bassCounter == 2) noteDurationsBass2.push_back(14);
							else if (bassCounter == 3) noteDurationsBass3.push_back(14);
						}
					}
					else {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(8); // add duration to end of the list
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(8); // add duration to end of the list
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(8); // add duration to end of the list
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(8); // add duration to end of the list
							else if (bassCounter == 2) noteDurationsBass2.push_back(8); // add duration to end of the list
							else if (bassCounter == 3) noteDurationsBass3.push_back(8); // add duration to end of the list
						}
					}
				}
				else if (findSixteenth != string::npos) { // sixteenth note
					if (findDotted != string::npos) {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(15); // 15 = Dotted Sixteenth 
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(15);
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(15);
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(15);
							else if (bassCounter == 2) noteDurationsBass2.push_back(15);
							else if (bassCounter == 3) noteDurationsBass3.push_back(15);
						}
					}
					else {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(16); // add duration to end of the list
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(16); // add duration to end of the list
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(16); // add duration to end of the list
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(16); // add duration to end of the list
							else if (bassCounter == 2) noteDurationsBass2.push_back(16); // add duration to end of the list
							else if (bassCounter == 3) noteDurationsBass3.push_back(16); // add duration to end of the list
						}
					}
				}
				else if (findThirty != string::npos) { // thirtysecondth note
					if (findDotted != string::npos) {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(17); // 17 = Dotted Thirty-secondth
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(17);
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(17);
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(17);
							else if (bassCounter == 2) noteDurationsBass2.push_back(17);
							else if (bassCounter == 3) noteDurationsBass3.push_back(17);
						}
					}
					else {
						if (clef == "Treble\n") {
							if (trebleCounter == 1) noteDurationsTreble1.push_back(32); // add duration to end of the list
							else if (trebleCounter == 2) noteDurationsTreble2.push_back(32); // add duration to end of the list
							else if (trebleCounter == 3) noteDurationsTreble3.push_back(32); // add duration to end of the list
						}
						else if (clef == "Bass\n") {
							if (bassCounter == 1) noteDurationsBass1.push_back(32); // add duration to end of the list
							else if (bassCounter == 2) noteDurationsBass2.push_back(32); // add duration to end of the list
							else if (bassCounter == 3) noteDurationsBass3.push_back(32); // add duration to end of the list
						}
					}
				}
			}

			if (line == "Rest") { // add 30 to end of noteType list if line variable is equal to "Rest"
				if (clef == "Treble\n") {
					if (trebleCounter == 1) notePositionsTreble1.push_back("x"); // add duration to end of the list
					else if (trebleCounter == 2) notePositionsTreble2.push_back("x"); // add duration to end of the list
					else if (trebleCounter == 3) notePositionsTreble3.push_back("x"); // add duration to end of the list
				}
				else if (clef == "Bass\n") {
					if (bassCounter == 1) notePositionsBass1.push_back("x"); // add duration to end of the list
					else if (bassCounter == 2) notePositionsBass2.push_back("x"); // add duration to end of the list
					else if (bassCounter == 3) notePositionsBass3.push_back("x"); // add duration to end of the list
				}
			}

			findDuration = previousLine.find("Dur:"); // check if previous line contained "Dur:"
			if (findPosition != string::npos) { // if findPosition is not at position 0 (invalid position)
				if (findDuration != string::npos) {  // if findDuration is not at position 0 (invalid position)
					if (clef == "Treble\n") {
						position = line.substr(findPosition + 4); // set position equal to string after "Pos:"
						if (trebleCounter == 1) notePositionsTreble1.push_back(position); // add value of position to end of notePositionsTreble1 list
						else if (trebleCounter == 2) notePositionsTreble2.push_back(position); // add value of position to end of notePositionsTreble2 list
						else if (trebleCounter == 3) notePositionsTreble3.push_back(position); // add value of position to end of notePositionsTreble3 list
					}
					if (clef == "Bass\n") {
						position = line.substr(findPosition + 4); // set position equal to string after "Pos:"
						if (bassCounter == 1) notePositionsBass1.push_back(position); // add value of position to end of notePositionsBass1 list
						else if (bassCounter == 2) notePositionsBass2.push_back(position); // add value of position to end of notePositionsBass2 list
						else if (bassCounter == 3) notePositionsBass3.push_back(position); // add value of position to end of notePositionsBass3 list
					}
				}
			}

			previousLine = line; // set previous line equal to line then go to next line
		}
		inFile.close(); // close input file
	}
	else cout << "Unable to open file" << endl; // if file is not found

	outFile << "Tempo is " << tempo << endl; // print value of tempo variable

	if (trebleCounter >= 1) {
		outFile << endl << endl << "Note Durations Treble1: ";
		for (std::list<int>::iterator it = noteDurationsTreble1.begin(); it != noteDurationsTreble1.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}

		outFile << endl << endl << "Note Positions Treble1: ";
		for (std::list<string>::iterator it = notePositionsTreble1.begin(); it != notePositionsTreble1.end(); it++) { // print out each element in the list
			temp = *it;
			counter = 0;
			if (temp == "x") counterArrayTreble1.push_back(0);
			else {
				outFile << *it << ",";
				for (int y = 0; y < temp.size(); y++) {
					comma = temp[y];
					if (comma == ',') counter++;
				}
				counterArrayTreble1.push_back(counter + 1);
			}
		}

		outFile << endl << endl << "Counter Treble1: ";
		for (std::list<int>::iterator it = counterArrayTreble1.begin(); it != counterArrayTreble1.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}
	}

	if (trebleCounter >= 2) {
		outFile << endl << endl << "Note Durations Treble2: ";
		for (std::list<int>::iterator it = noteDurationsTreble2.begin(); it != noteDurationsTreble2.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}

		outFile << endl << endl << "Note Positions Treble2: ";
		for (std::list<string>::iterator it = notePositionsTreble2.begin(); it != notePositionsTreble2.end(); it++) { // print out each element in the list
			temp = *it;
			counter = 0;
			if (temp == "x") counterArrayTreble2.push_back(0);
			else {
				outFile << *it << ",";
				for (int y = 0; y < temp.size(); y++) {
					comma = temp[y];
					if (comma == ',') counter++;
				}
				counterArrayTreble2.push_back(counter + 1);
			}
		}

		outFile << endl << endl << "Counter Treble2: ";
		for (std::list<int>::iterator it = counterArrayTreble2.begin(); it != counterArrayTreble2.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}
	}

	if (trebleCounter == 3) {
		outFile << endl << endl << "Note Durations Treble3: ";
		for (std::list<int>::iterator it = noteDurationsTreble3.begin(); it != noteDurationsTreble3.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}

		outFile << endl << endl << "Note Positions Treble3: ";
		for (std::list<string>::iterator it = notePositionsTreble3.begin(); it != notePositionsTreble3.end(); it++) { // print out each element in the list
			temp = *it;
			counter = 0;
			if (temp == "x") counterArrayTreble3.push_back(0);
			else {
				outFile << *it << ",";
				for (int y = 0; y < temp.size(); y++) {
					comma = temp[y];
					if (comma == ',') counter++;
				}
				counterArrayTreble3.push_back(counter + 1);
			}
		}

		outFile << endl << endl << "Counter Treble3: ";
		for (std::list<int>::iterator it = counterArrayTreble3.begin(); it != counterArrayTreble3.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}
	}

	if (bassCounter >= 1) {
		outFile << endl << endl << "Note Durations Bass1: ";
		for (std::list<int>::iterator it = noteDurationsBass1.begin(); it != noteDurationsBass1.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}

		outFile << endl << endl << "Note Positions Bass1: ";
		for (std::list<string>::iterator it = notePositionsBass1.begin(); it != notePositionsBass1.end(); it++) { // print out each element in the list
			temp = *it;
			counter = 0;
			if (temp == "x") counterArrayBass1.push_back(0);
			else {
				outFile << *it << ",";
				for (int y = 0; y < temp.size(); y++) {
					comma = temp[y];
					if (comma == ',') counter++;
				}
				counterArrayBass1.push_back(counter + 1);
			}
		}

		outFile << endl << endl << "Counter Bass1: ";
		for (std::list<int>::iterator it = counterArrayBass1.begin(); it != counterArrayBass1.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}
	}

	if (bassCounter >= 2) {
		outFile << endl << endl << "Note Durations Bass2: ";
		for (std::list<int>::iterator it = noteDurationsBass2.begin(); it != noteDurationsBass2.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}

		outFile << endl << endl << "Note Positions Bass2: ";
		for (std::list<string>::iterator it = notePositionsBass2.begin(); it != notePositionsBass2.end(); it++) { // print out each element in the list
			temp = *it;
			counter = 0;
			if (temp == "x") counterArrayBass2.push_back(0);
			else {
				outFile << *it << ",";
				for (int y = 0; y < temp.size(); y++) {
					comma = temp[y];
					if (comma == ',') counter++;
				}
				counterArrayBass2.push_back(counter + 1);
			}
		}

		outFile << endl << endl << "Counter Bass2: ";
		for (std::list<int>::iterator it = counterArrayBass2.begin(); it != counterArrayBass2.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}
	}

	if (bassCounter == 3) {
		outFile << endl << endl << "Note Durations Bass3: ";
		for (std::list<int>::iterator it = noteDurationsBass3.begin(); it != noteDurationsBass3.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}

		outFile << endl << endl << "Note Positions Bass3: ";
		for (std::list<string>::iterator it = notePositionsBass3.begin(); it != notePositionsBass3.end(); it++) { // print out each element in the list
			temp = *it;
			counter = 0;
			if (temp == "x") counterArrayBass3.push_back(0);
			else {
				outFile << *it << ",";
				for (int y = 0; y < temp.size(); y++) {
					comma = temp[y];
					if (comma == ',') counter++;
				}
				counterArrayBass3.push_back(counter + 1);
			}
		}

		outFile << endl << endl << "Counter Bass3: ";
		for (std::list<int>::iterator it = counterArrayBass3.begin(); it != counterArrayBass3.end(); it++) { // print out each element in the list
			outFile << *it << ",";
		}
	}

	outFile.close(); // close output file

	return 0;
}
