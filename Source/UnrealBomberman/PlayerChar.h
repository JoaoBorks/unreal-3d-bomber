// Created by Joao Borks [joao.borks@gmail.com] 2018

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Bomb.h"
#include "BombDestroyable.h"
#include "PlayerChar.generated.h"

UCLASS()
class UNREALBOMBERMAN_API APlayerChar : public ACharacter, public IBombDestroyable
{
	GENERATED_BODY()

public:
	APlayerChar();

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite)
	TArray<ABomb*> PlacedBombs;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "1.0", ClampMax = "10.0"))
	int BombLimit = 1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "1.0", ClampMax = "10.0"))
	float BombRange = 2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool HasRemote = false;

	UFUNCTION(BlueprintCallable)
	void SpawnBomb();
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable)
	void OnBombBlastHit();
	virtual void OnBombBlastHit_Implementation() override;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UClass* BombBP;

	UFUNCTION(BlueprintCallable)
	FTransform& GetSnappedPosition(FTransform Source) const;

private:
	float GetSnappedValue(int Value, float Scale) const;
};