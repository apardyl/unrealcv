// Weichao Qiu @ 2017
#pragma once

#include "Sensor/CameraSensor/FusionCamSensor.h"
#include "Actor/CamSensorActor.h"
#include "Components/SphereComponent.h"
#include "Components/WorldPartitionStreamingSourceComponent.h"
#include "FusionCameraActor.generated.h"

UCLASS()
class UNREALCV_API AFusionCameraActor : public ACamSensorActor
{
	GENERATED_BODY()

public:
	AFusionCameraActor();

	// This can be extended to support multiple cameras
	virtual TArray<FString> GetSensorNames();

	virtual TArray<UFusionCamSensor*> GetSensors();

	bool IsLoaded() const;

private:
	// Define it to be VisibleAnywhere not EditableAnywhere. This is enough for changing the component property
	UPROPERTY(Category = AFusionCameraActor, VisibleAnywhere, BlueprintReadOnly, meta=(AllowPrivateAccess = "true"))
	UFusionCamSensor* FusionCamSensor;

	UPROPERTY(EditAnywhere)
	USphereComponent* CollisionSphere;

	UPROPERTY(EditAnywhere)
	UWorldPartitionStreamingSourceComponent* WorldPartitionStreamingSource;
};
