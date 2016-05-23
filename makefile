all: main.x

FLAGS = -ggdb -std=c++11 -Wall -Wextra

main.x: main_JSON.o dataObject.o dataItem.o jsonArray.o tracks.o track.o artists.o artist.o album.o albums.o artistImages.o artistImage.o albumImages.o albumImage.o
	g++ $(FLAGS) -o main.x main_JSON.o jsonArray.o dataObject.o dataItem.o tracks.o track.o artists.o artist.o album.o albums.o artistImages.o artistImage.o albumImages.o albumImage.o

main_JSON.o: main_JSON.cpp JSONDataObject.hpp JSONDataItem.hpp Track.hpp
	g++ $(FLAGS) -c -o main_JSON.o main_JSON.cpp

jsonArray.o: JSONArray.cpp JSONArray.hpp JSONDataObject.hpp
	g++ $(FLAGS) -c -o jsonArray.o JSONArray.cpp 

dataObject.o: JSONDataObject.cpp JSONDataObject.hpp JSONDataItem.hpp
	g++ $(FLAGS) -c -o dataObject.o JSONDataObject.cpp

dataItem.o: JSONDataItem.cpp JSONDataItem.hpp
	g++ $(FLAGS) -c -o dataItem.o JSONDataItem.cpp

tracks.o: Tracks.cpp Tracks.hpp JSONArray.hpp
	g++ $(FLAGS) -c -o tracks.o Tracks.cpp

track.o: Track.cpp Track.hpp
	g++ $(FLAGS) -c -o track.o Track.cpp

albums.o: Albums.cpp Albums.hpp JSONArray.hpp
	g++ $(FLAGS) -c -o albums.o Albums.cpp

album.o: Album.cpp Album.hpp
	g++ $(FLAGS) -c -o album.o Album.cpp

artists.o: Artists.cpp Artists.hpp JSONArray.hpp
	g++ $(FLAGS) -c -o artists.o Artists.cpp

artist.o: Artist.cpp Artist.hpp
	g++ $(FLAGS) -c -o artist.o Artist.cpp

artistImages.o: ArtistImages.cpp ArtistImages.hpp JSONArray.hpp
	g++ $(FLAGS) -c -o artistImages.o ArtistImages.cpp

artistImage.o: ArtistImage.cpp ArtistImage.hpp
	g++ $(FLAGS) -c -o artistImage.o ArtistImage.cpp

albumImages.o: AlbumImages.cpp AlbumImages.hpp JSONArray.hpp
	g++ $(FLAGS) -c -o albumImages.o AlbumImages.cpp

albumImage.o: AlbumImage.cpp AlbumImage.hpp
	g++ $(FLAGS) -c -o albumImage.o AlbumImage.cpp

run:
	./main.x

clean: 
	rm *.x *.o *.html ./html_albums/* 
