#pragma once
#include <string>
#include <vector>
#include <memory>
#include "IParentInfo.h"

class PrimitiveStep;

enum class EventType
{
	kNotDefined = 0,
	kMouseClickL,
	kMouseClickR,
	kKeysType,
	kPushKeyButton,
	kPushKeyButtons
};

static std::vector<std::string> enum_string
{
	"NotDefined",
	"MouseClickL",
	"MouseClickR",
	"KeysType",
	"PushKeyButton",
	"PushKeyButtons"
};

class IStep
{
public:
	// Start of Constructors
	IStep() = default;
	// End of Constructors

	// Destructor
	virtual ~IStep() = default;

	/** Converts event type (Enum) of actual step to string
	* @param returnParam: is a conversion of actual step's event type (Enum) to string
	*/
	virtual std::string EnumToString() = 0;

	/** Converts given string to event type (Enum) if possible
	* @param strV: is a string value which will be converted to enum
	* @param returnParam: is Event Type (Enum) value from converted string, or is Not Defined Event Type if the conversion is not possible
	*/
	virtual EventType StringToEnum(const std::string& strV) = 0;

	/** TODO
	* @param TODO
	*/
	virtual bool CompareStepWithoutParentsPtr(const IStep& tmp) const = 0;

	/** Gets automation identifier from automation IDs' UIA information
	* @param returnParam: string value of automation identifier
	*/
	virtual std::string GetAutomationIdUIA()const = 0;

	/** Sets automation identifier
	* @param autoID: string value of automation identifier
	*/
	virtual void SetAutomationId(std::string autoID) = 0;

	/** Gets class name from classes's UIA information
	* @param returnParam: string value of class name
	*/
	virtual std::string GetClassNameUIA() const = 0;

	/** Sets class name
	* @param className: string value of class name
	*/
	virtual void SetClassName(std::string className) = 0;

	/** Gets control type from control types' UIA information
	* @param returnParam: string value of control type
	*/
	virtual std::string GetControlTypeUIA()const = 0;

	/** Sets control type
	* @param controlType: string value of control type
	*/
	virtual void SetControlType(std::string controlType) = 0;

	/** Gets item type from item types' UIA information
	* @param returnParam: string value of control type
	*/
	virtual std::string GetItemTypeUIA() const = 0;

	/** Sets item type
	* @param itemType: string value of item type
	*/
	virtual void SetItemType(std::string itemType) = 0;

	/** Gets single key data of the step
	* @param returnParam: key data as a char
	*/
	virtual char GetKeyData() const = 0;

	/** Sets key data
	* @param itemType: string value of key data
	*/
	virtual void SetKeyData(char keyData) = 0;

	/** Gets event type of the step
	* @param returnParam: event type (Enum)
	*/
	virtual EventType GetStepEvent() const = 0;

	/** Sets event type
	* @param eventType: event type (Enum) value
	*/
	virtual void SetStepEvent(EventType eventType) = 0;

	/** Gets name of selected widget from widget's UIA information
	* @param returnParam: string value of widget name
	*/
	virtual std::string GetWidgetNameUIA()const = 0;

	/** Sets widget name
	* @param widgetName: string value of widget name
	*/
	virtual void SetWidgetName(std::string widgetName) = 0;

	virtual bool operator==(const IStep& tmp) = 0;
};