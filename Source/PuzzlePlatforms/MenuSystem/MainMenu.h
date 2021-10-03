// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MenuWidget.h"
#include "MainMenu.generated.h"

class UButton;
class UPanelWidget;
class UUserWidget;
class UWidget;
class UWidgetSwitcher;

UCLASS()
class PUZZLEPLATFORMS_API UMainMenu : public UMenuWidget
{
	GENERATED_BODY()

public:
	UMainMenu(const FObjectInitializer& ObjectInitializer);

	void SetServerList(const TArray<FString> ServerNames);
	
protected:
	virtual bool Initialize();

private:

	TSubclassOf<UUserWidget> ServerRowClass;
	
	UPROPERTY(meta = (BindWidget))
	UButton* HostButton;
	
	UPROPERTY(meta = (BindWidget))
	UButton* JoinButton;

	UPROPERTY(meta = (BindWidget))
	UButton* QuitButton;

	UPROPERTY(meta = (BindWidget))
	UButton* CancelJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	UButton* ConfirmJoinMenuButton;

	UPROPERTY(meta = (BindWidget))
	UWidgetSwitcher* MenuSwitcher;

	UPROPERTY(meta = (BindWidget))
	UWidget* MainMenu;

	UPROPERTY(meta = (BindWidget))
	UWidget* JoinMenu;

	UPROPERTY(meta = (BindWidget))
	UPanelWidget* ServerList;

	UFUNCTION()
	void HostServer();

	UFUNCTION()
	void JoinServer();


	UFUNCTION()
	void OpenJoinMenu();

	UFUNCTION()
	void OpenMainMenu();

	UFUNCTION()
	void QuitPressed();
};
