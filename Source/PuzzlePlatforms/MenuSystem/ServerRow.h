// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ServerRow.generated.h"

class UButton;
class UMainMenu;

class UTextBlock;

UCLASS()
class PUZZLEPLATFORMS_API UServerRow : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UTextBlock* ServerName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* HostName;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* PlayersNum;

private:
	UPROPERTY(meta = (BindWidget))
	UButton* RowButton;

	UPROPERTY()
	UMainMenu* ParentMenu;

	uint32 ServerIndex;
public:
    void Setup(UMainMenu* ParentMenu, uint32 Index);
	
private:
	UFUNCTION()
	void OnRowButtonClicked();
};
