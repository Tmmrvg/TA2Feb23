// Fill out your copyright notice in the Description page of Project Settings.


#include "GameController.h"

#include <d3d10sdklayers.h>

#include "Target.h"
#include "../../../../EpicLibrary/UE_5.1/Engine/Shaders/Private/PhysicsFieldEval.ush"

AGameController::AGameController()
{
	WaveSize.Add(10);
	WaveSize.Add(15);
	WaveSize.Add(20);

	WaveDifficulty.Add(0.5);
	WaveDifficulty.Add(1);
	WaveDifficulty.Add(2);

	WaveSpawnFrequency.Add(2);
	WaveSpawnFrequency.Add(1);
	WaveSpawnFrequency.Add(0.5);

	MinX = 2000;
	MaxX = 2200;

	MinY = -400;
	MaxY = 400;
}

void AGameController::BeginPlay()
{
	Super::BeginPlay();

	CurrentWave = 1;
	LeftToSpawn = WaveSize[CurrentWave - 1];
}

void AGameController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	Clock +=DeltaTime;

	if (Clock > WaveSpawnFrequency[CurrentWave - 1])
	{
		Clock = 0.f;
		FVector Location = FVector(FMath::RandRange(MinX, MaxX), FMath::RandRange(MinY, MaxY));

		AActor* Actor = GetWorld()->SpawnActor<AActor>(Target_BP, Location, FRotator::ZeroRotator);
		ATarget* Target = Cast<ATarget>(Actor);

		Target->MovementSpeed *= WaveDifficulty[CurrentWave];
	}

	
}


