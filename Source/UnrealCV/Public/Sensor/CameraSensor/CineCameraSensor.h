#pragma once

#include "Runtime/CinematicCamera/Public/CineCameraComponent.h"
#include "CineCameraSceneCaptureComponent.h"
#include "CineCameraSensor.generated.h"


UCLASS(meta = (BlueprintSpawnableComponent))
class UNREALCV_API UCineCamSensor : public UCineCameraComponent
{
	GENERATED_BODY()
public:
	UCineCamSensor();
	UPROPERTY(EditDefaultsOnly, Category = "unrealcv")
	class UCineCaptureComponent2D* CinematicCaptureSensor;

	void SetParams(float sensorSizeMm, float focalLenghtMm, int sensorPx);
};
