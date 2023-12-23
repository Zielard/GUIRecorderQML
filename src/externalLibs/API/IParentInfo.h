#pragma once
#ifndef IPARENTINFO_H
#define IPARENTINFO_H
#include <string>
#include <memory>

class IParentInfo
{
public:
	// Start of Constructors
	IParentInfo() = default;
	// End of Constructors

	/** Sets pointer to the actual parent
	* @param parent_: is a shared pointer to ParentInfo object
	*/
	virtual void SetParent(std::shared_ptr<IParentInfo> parent_) = 0;

	/** Gets pointer of the parent
	* @param returnParam: is an ParentInfo object
	*/
	virtual std::shared_ptr<IParentInfo> GetParent() = 0;

	/** Returns content of the Parentnfo object as std::string in format of JSON
	* @param distance: it is a tabulation information saying how deep is the space between element and the line edge
	* @param rV: is std::string that stores ParentInfo content in JSON format
	*/
	virtual std::string ToString(std::string distance) = 0;

	virtual bool operator==(const IParentInfo& tmp) = 0;
};
#endif //IPARENTINFO_H