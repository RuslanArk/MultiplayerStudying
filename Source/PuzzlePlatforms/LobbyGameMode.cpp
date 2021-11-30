// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"

#include "PuzzlePlatformsGameInstance.h"

DEFINE_LOG_CATEGORY_STATIC(LogLobbyGameMode, All, All);

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	++NumberOfPlayers;

	if (NumberOfPlayers >= 3)
	{
		GetWorldTimerManager().SetTimer(ServerTravelTimer, this, &ALobbyGameMode::StartGame, 10.0f);		
	}
}

void ALobbyGameMode::Logout(AController* Exiting)
{
	Super::Logout(Exiting);

	--NumberOfPlayers;
}

void ALobbyGameMode::StartGame()
{
	UPuzzlePlatformsGameInstance* GameInstance = Cast<UPuzzlePlatformsGameInstance>(GetGameInstance());
	if (!GameInstance) return;

	GameInstance->StartSession();
	
	UWorld* World = GetWorld();
	if (!World) return;

	bUseSeamlessTravel = true;
		
	World->ServerTravel("/Game/PuzzlePlatforms/Maps/MainLevel?listen");
}
