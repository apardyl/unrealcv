// Weichao Qiu @ 2017

#include "FusionCameraActor.h"

AFusionCameraActor::AFusionCameraActor()
	: Super()
{
	PrimaryActorTick.bCanEverTick = true;

	CollisionSphere = CreateDefaultSubobject<USphereComponent>(TEXT("SphereMesh"));
	CollisionSphere->SetSphereRadius(100); // 1m collision radius.
	CollisionSphere->SetCollisionProfileName(TEXT("BlockAllDynamic"));
	RootComponent = CollisionSphere;

	FusionCamSensor = CreateDefaultSubobject<UFusionCamSensor>(TEXT("FusionCameraSensor"));
	FusionCamSensor->SetupAttachment(RootComponent);
}

TArray<FString> AFusionCameraActor::GetSensorNames()
{
	return { this->GetName() };
}

TArray<UFusionCamSensor*> AFusionCameraActor::GetSensors()
{
	return { this->FusionCamSensor };
}