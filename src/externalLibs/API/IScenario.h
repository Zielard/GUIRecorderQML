#pragma once
#include <string>
#include <vector>
#include "IStep.h"
class IScenario
{

public:
	// Start of Constructors
	IScenario() = default;
	// End of Constructors

	/** Returns content of the Scenario as std::string
	* @param rV: is a std::string variable which stores a content of a single Scenario created during record of user's steps
	*/
	virtual std::string ToString() = 0;

	/** TODO Returns bool value after loading a JSON file: true if successful, false if not
	* @param path: is a path to the file which user wants to load
	* @param rV: is a bool value which states if loading proccess was successful or not
	*/
	virtual void LoadFromJson(std::string path) = 0;

	/** Returns bool value after writing to JSON file: true if successful, false if not
	* @param path: is a path to the place where user wants to save the file
	* @param rV: is a bool value which states if writing proccess was successful or not
	*/
	virtual bool WriteToJson(std::string path) = 0;

	///** Sets recorded steps done by the user to the vector of Steps
	//* @param step: is a step which user has done and which will be stored in the steps vector
	//*/
	//virtual void SetRecordSteps(const std::vector<IStep*>& steps) = 0;

	/** Gets recorded and stored steps from the vector of Steps
	* @param returnParam: is a vector of recorded steps done by a user during a single record
	*/
	virtual std::vector<IStep*> GetRecordISteps() = 0;
};
