#include <iostream>
#include <string>
#include <vector>
using namespace std;

class MediaFile
{
protected:
    string filePath;
    size_t fileSize;
public:
    MediaFile(const string &path, size_t size)
        : filePath(path), fileSize(size) {}
    virtual void play()
    {
        cout << "Playing media file: " << filePath << endl;
    }
    virtual void stop()
    {
        cout << "Stopping media file: " << filePath << endl;
    }
    virtual ~MediaFile() = default;
};
class VisualMedia : virtual public MediaFile
{
protected:
    int resolutionWidth;
    int resolutionHeight;
public:
    VisualMedia(const string &path, size_t size, int width, int height)
        : MediaFile(path, size), resolutionWidth(width), resolutionHeight(height) {}
    void displayResolution() const
    {
        cout << "Resolution: " << resolutionWidth << "x" << resolutionHeight << endl;
    }
};
class AudioMedia : virtual public MediaFile
{
protected:
    int sampleRate;
public:
    AudioMedia(const string &path, size_t size, int rate)
        : MediaFile(path, size), sampleRate(rate) {}
    void displaySampleRate() const
    {
        cout << "Sample Rate: " << sampleRate << " Hz" << endl;
    }
};
class VideoFile : public VisualMedia, public AudioMedia
{
public:
    VideoFile(const string &path, size_t size, int width, int height, int rate)
        : MediaFile(path, size), // Call the base class constructor directly
          VisualMedia(path, size, width, height),
          AudioMedia(path, size, rate)
    {
    }
    void play() override
    {
        cout << "Playing video file: " << filePath << endl;
        displayResolution();
        displaySampleRate();
    }
    void stop() override
    {
        cout << "Stopping video file: " << filePath << endl;
    }
};
class ImageFile : public VisualMedia
{
public:
    ImageFile(const string &path, size_t size, int width, int height)
        : MediaFile(path, size), VisualMedia(path, size, width, height) {}
    void play() override
    {
        cout << "Displaying image file: " << filePath << endl;
        displayResolution();
    }
    void stop() override
    {
        cout << "Closing image file: " << filePath << endl;
    }
};
class AudioFile : public AudioMedia
{
public:
    AudioFile(const string &path, size_t size, int rate)
        : MediaFile(path, size), AudioMedia(path, size, rate) {}
    void play() override
    {
        cout << "Playing audio file: " << filePath << endl;
        displaySampleRate();
    }
    void stop() override
    {
        cout << "Stopping audio file: " << filePath << endl;
    }
};
MediaFile *createMediaFile()
{
    string type, path;
    size_t size;
    int width, height, rate;
    cout << "Enter media type (video/image/audio): ";
    cin >> type;
    cout << "Enter file path: ";
    cin >> path;
    cout << "Enter file size (in KB): ";
    cin >> size;
    if (type == "video")
    {
        cout << "Enter resolution width: ";
        cin >> width;
        cout << "Enter resolution height: ";
        cin >> height;
        cout << "Enter sample rate (in Hz): ";
        cin >> rate;
        return new VideoFile(path, size, width, height, rate);
    }
    else if (type == "image")
    {
        cout << "Enter resolution width: ";
        cin >> width;
        cout << "Enter resolution height: ";
        cin >> height;
        return new ImageFile(path, size, width, height);
    }
    else if (type == "audio")
    {
        cout << "Enter sample rate (in Hz): ";
        cin >> rate;
        return new AudioFile(path, size, rate);
    }
    else
    {
        cout << "Invalid media type!" << endl;
        return nullptr;
    }
}
int main()
{
    vector<MediaFile *> mediaLibrary;
    char choice;
    do
    {
        MediaFile *media = createMediaFile();
        if (media)
        {
            mediaLibrary.push_back(media);
        }
        cout << "Do you want to add another media file? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');
    for (auto media : mediaLibrary)
    {
        media->play();
        media->stop();
    }
    for (auto media : mediaLibrary)
    {
        delete media;
    }
    return 0;
}