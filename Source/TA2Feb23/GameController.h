// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameController.generated.h"
class ATarget;
struct Wave
{
	Wave(int s, int d)
	{
		Size = s;
		Difficulty = d;
	}
	int Size;
	int Difficulty;
};
/**
 * 
 */
UCLASS()
class TA2FEB23_API AGameController : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameController();

protected:
	//Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//Called every frame
	virtual void Tick(float DeltaSeconds) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variable")
	TArray<float> WaveDifficulty;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variable")
	TArray<int> WaveSize;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variable")
	TArray<int> WaveSpawnFrequency;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variable")
	float MinX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variable")
	float MaxX;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variable")
	float MinY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variable")
	float MaxY;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variable")
	int CurrentWave;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "My Variables")
	TSubclassOf<ATarget> Target_BP;

private:
	int LeftToSpawn;
	float Clock;
	float SpawnFrequency;
};
