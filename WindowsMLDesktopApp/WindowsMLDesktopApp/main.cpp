#include "pch.h"

using namespace winrt;
using namespace Windows::Foundation;

using namespace Windows::AI::MachineLearning;
using namespace Windows::Foundation::Collections;
using namespace Windows::Graphics::Imaging;
using Windows::Media::VideoFrame;
using namespace Windows::Storage;

//using namespace std;

// Global variables
// Miscellaneous Path
winrt::hstring modelPath = L"./model/SqueezeNet.onnx";
const std::string deviceName{ "default" };
winrt::hstring imagePath = L"C:\\Users\\hux1mis\\source\\repos\\EmbeddedProgramming\\WindowsMLDesktopApp\\WindowsMLDesktopApp\\image\\kitten_224.png";

// Windows::AI::MachineLearning types
winrt::Windows::AI::MachineLearning::LearningModel model = nullptr;
winrt::Windows::AI::MachineLearning::LearningModelDeviceKind deviceKind = LearningModelDeviceKind::Default;
winrt::Windows::AI::MachineLearning::LearningModelSession session = nullptr;
winrt::Windows::AI::MachineLearning::LearningModelBinding binding = nullptr;

VideoFrame imageFrame = nullptr;
std::string labelsFilePath = "./label/labels.txt";
std::vector<std::string> labels;

// Forward declarations
void LoadModel();
VideoFrame LoadImageFile(hstring filePath);
void BindModel();
void EvaluateModel();
void PrintResults(IVectorView<float> results);
void LoadLabels();

int main()
{
    init_apartment();

    LoadModel();
    imageFrame = LoadImageFile(imagePath);
    BindModel();
    EvaluateModel();
}

void LoadModel()
{
    // load the model
    printf("Loading modelfile '%ws' on the '%s' device\n", modelPath.c_str(), deviceName.c_str());
    ULONGLONG ticks = GetTickCount64();
    model = LearningModel::LoadFromFilePath(modelPath);
    ticks = GetTickCount64() - ticks;
    printf("model file loaded in %llu ticks\n", ticks);

    return;
}

VideoFrame LoadImageFile(hstring filePath)
{
    printf("Loading the image...\n");
    ULONGLONG ticks = GetTickCount64();
    VideoFrame inputImage = nullptr;

    try
    {
        // open the file
        StorageFile file = StorageFile::GetFileFromPathAsync(filePath).get();
        // get a stream on it
        auto stream = file.OpenAsync(FileAccessMode::Read).get();
        // Create the decoder from the stream
        BitmapDecoder decoder = BitmapDecoder::CreateAsync(stream).get();
        // get the bitmap
        SoftwareBitmap softwareBitmap = decoder.GetSoftwareBitmapAsync().get();
        // load a videoframe from it
        inputImage = VideoFrame::CreateWithSoftwareBitmap(softwareBitmap);
    }
    catch (...)
    {
        printf("failed to load the image file, make sure you are using fully qualified paths\r\n");
        exit(EXIT_FAILURE);
    }

    ticks = GetTickCount64() - ticks;
    printf("image file loaded in %llu ticks\n", ticks);
    // all done
    return inputImage;
}

void BindModel()
{
    printf("Binding the model...\n");
    ULONGLONG ticks = GetTickCount64();

    // now create a session and binding
    session = LearningModelSession{ model, LearningModelDevice(deviceKind) };
    binding = LearningModelBinding{ session };
    // bind the intput image
    binding.Bind(L"data_0", ImageFeatureValue::CreateFromVideoFrame(imageFrame));
    // bind the output
    std::vector<int64_t> shape({ 1, 1000, 1, 1 });
    binding.Bind(L"softmaxout_1", TensorFloat::Create(shape));

    ticks = GetTickCount64() - ticks;
    printf("Model bound in %llu ticks\n", ticks);

    return;
}

void EvaluateModel()
{
    // now run the model
    printf("Running the model...\n");
    ULONGLONG ticks = GetTickCount64();

    winrt::Windows::AI::MachineLearning::LearningModelEvaluationResult results = session.Evaluate(binding, L"RunId");

    ticks = GetTickCount64() - ticks;
    printf("model run took %llu ticks\n", ticks);

    // get the output
    auto resultTensor = results.Outputs().Lookup(L"softmaxout_1").as<TensorFloat>();
    auto resultVector = resultTensor.GetAsVectorView();
    PrintResults(resultVector);
}

void PrintResults(IVectorView<float> results)
{
    // load the labels
    LoadLabels();
    // Find the top 3 probabilities
    std::vector<float> topProbabilities(3);
    std::vector<int> topProbabilityLabelIndexes(3);
    // SqueezeNet returns a list of 1000 options, with probabilities for each, loop through all
    for (uint32_t i = 0; i < results.Size(); i++)
    {
        // is it one of the top 3?
        for (int j = 0; j < 3; j++)
        {
            if (results.GetAt(i) > topProbabilities[j])
            {
                topProbabilityLabelIndexes[j] = i;
                topProbabilities[j] = results.GetAt(i);
                break;
            }
        }
    }
    // Display the result
    for (int i = 0; i < 3; i++)
    {
        printf("%s with confidence of %f\n", labels[topProbabilityLabelIndexes[i]].c_str(), topProbabilities[i]);
    }
}

void LoadLabels()
{
    // Parse labels from labels file.  We know the file's entries are already sorted in order.
    std::ifstream labelFile{ labelsFilePath, std::ifstream::in };
    if (labelFile.fail())
    {
        printf("failed to load the %s file.  Make sure it exists in the same folder as the app\r\n", labelsFilePath.c_str());
        exit(EXIT_FAILURE);
    }

    std::string s;
    while (std::getline(labelFile, s, ','))
    {
        int labelValue = atoi(s.c_str());
        if (labelValue >= labels.size())
        {
            labels.resize(labelValue + 1);
        }
        std::getline(labelFile, s);
        labels[labelValue] = s;
    }
}
