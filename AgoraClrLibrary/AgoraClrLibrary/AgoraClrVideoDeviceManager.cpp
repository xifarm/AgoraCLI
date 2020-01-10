#include "stdafx.h"
#include "AgoraClrVideoDeviceManager.h"
#include "AgoraClrLibrary.h"
#include "ConvertStringHelp.h"

AgoraClrLibrary::ClrVideoDeviceCollection::ClrVideoDeviceCollection(IVideoDeviceCollection * rawCollection):raw(rawCollection)
{
	
}

AgoraClrLibrary::ClrVideoDeviceCollection::~ClrVideoDeviceCollection()
{
	//this->release();
	this->!ClrVideoDeviceCollection();
}

AgoraClrLibrary::ClrVideoDeviceCollection::!ClrVideoDeviceCollection()
{
	
}

int AgoraClrLibrary::ClrVideoDeviceCollection::getCount()
{
	return raw != NULL ? raw->getCount() : 0;
}

int AgoraClrLibrary::ClrVideoDeviceCollection::getDevice(int index, String ^% deviceName, String ^% deviceId)
{
	char deviceNameBuffer[MAX_DEVICE_ID_LENGTH] = { 0 }; char deviceIdBuffer[MAX_DEVICE_ID_LENGTH] = { 0 };
	int result = raw->getDevice(index, deviceNameBuffer, deviceIdBuffer);
	if (result != 0) return result;
	deviceName = ConvertUNICODE2String(deviceNameBuffer);

	/*deviceName = gcnew String(deviceNameBuffer), */
	deviceId = gcnew String(deviceIdBuffer);
	return result;
	// return raw->getDevice(index, const_cast<char*>(MarshalString(deviceName).c_str()), const_cast<char*>(MarshalString(deviceId).c_str()));
}

int AgoraClrLibrary::ClrVideoDeviceCollection::setDevice(String ^ deviceId)
{
	return raw != NULL ? raw->setDevice(const_cast<char*>(MarshalString(deviceId).c_str())) : -1;
}


//void AgoraClrLibrary::ClrVideoDeviceCollection::release()
//{
//	//raw->release();
//}


AgoraClrLibrary::AgoraClrVideoDeviceManager::AgoraClrVideoDeviceManager(AgoraClr ^ engine)
{
	this->engine = engine;
}

AgoraClrLibrary::ClrVideoDeviceCollection ^ AgoraClrLibrary::AgoraClrVideoDeviceManager::enumerateVideoDevices()
{
	AVideoDeviceManager manager(engine->getEngine());
	agora::rtc::IVideoDeviceCollection* ss = manager != NULL ? manager->enumerateVideoDevices() : NULL;
	return gcnew ClrVideoDeviceCollection(ss);
}

int AgoraClrLibrary::AgoraClrVideoDeviceManager::setDevice(String ^ deviceId)
{
	AVideoDeviceManager manager(engine->getEngine());
	if (manager == NULL) return -1;
	return manager->setDevice(MarshalString(deviceId).c_str());
}

int AgoraClrLibrary::AgoraClrVideoDeviceManager::getDevice(String ^ deviceId)
{
	AVideoDeviceManager manager(engine->getEngine());
	if (manager == NULL) return -1;
	return manager->getDevice(const_cast<char*>(MarshalString2(deviceId).c_str()));
}

int AgoraClrLibrary::AgoraClrVideoDeviceManager::startDeviceTest(IntPtr hwnd)
{
	AVideoDeviceManager manager(engine->getEngine());
	if (manager == NULL) return -1;
	return manager->startDeviceTest(hwnd.ToPointer());
}

int AgoraClrLibrary::AgoraClrVideoDeviceManager::stopDeviceTest()
{
	AVideoDeviceManager manager(engine->getEngine());
	if (manager == NULL) return -1;
	return manager->stopDeviceTest();
}
