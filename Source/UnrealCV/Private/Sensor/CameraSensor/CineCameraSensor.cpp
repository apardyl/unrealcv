#include "CineCameraSensor.h"
#include "Runtime/CinematicCamera/Public/CineCameraSettings.h"

UCineCamSensor::UCineCamSensor()
	: Super()
{
	FString ComponentName;
	ComponentName = FString::Printf(TEXT("%s_%s"), *this->GetName(), TEXT("CinematicCaptureSensor"));
	CinematicCaptureSensor = CreateDefaultSubobject<UCineCaptureComponent2D>(*ComponentName);
	CinematicCaptureSensor->SetupAttachment(this);

	this->SetParams(35, 18, 4 * 224);
}

void UCineCamSensor::SetParams(float sensorSizeMm, float focalLenghtMm, int sensorPx) {
	FCameraFilmbackSettings filmbackSettings;
	filmbackSettings.SensorAspectRatio = 1.;
	filmbackSettings.SensorHeight = sensorSizeMm;
	filmbackSettings.SensorWidth = sensorSizeMm;
	this->SetFilmback(filmbackSettings);
	this->SetCurrentFocalLength(focalLenghtMm);
	this->CinematicCaptureSensor->RenderTargetHighestDimension = sensorPx;
}