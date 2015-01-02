//----------------------------------------------------------------------------
//  Copyright (C) 2004-2013 by EMGU. All rights reserved.       
//----------------------------------------------------------------------------
using System;
using System.Collections.Generic;
using System.Diagnostics;
using CoreGraphics;
using System.Drawing;
using System.Linq;
using Emgu.CV;
using Emgu.CV.Structure;
using MonoTouch.Dialog;
using Foundation;
using UIKit;
using TrafficSignRecognition;

namespace Emgu.CV.Example.MonoTouch
{
   public class TrafficSignRecognitionDialogViewController : ButtonMessageImageDialogViewController
   {
      public TrafficSignRecognitionDialogViewController()
         : base()
      {
      }

      public override void ViewDidLoad()
      {
         base.ViewDidLoad();
         ButtonText = "Detect Stop Sign";
         OnButtonClick +=
         delegate
         {
            using (Image<Bgr, byte> stopSignModel = new Image<Bgr, byte>("stop-sign-model.png"))
            using (Image<Bgr, Byte> image = new Image<Bgr, Byte>("stop-sign.jpg"))
            {
               Stopwatch watch = Stopwatch.StartNew(); // time the detection process

               List<Image<Gray, Byte>> stopSignList = new List<Image<Gray, byte>>();
               List<Rectangle> stopSignBoxList = new List<Rectangle>();
               StopSignDetector detector = new StopSignDetector(stopSignModel);
               detector.DetectStopSign(image, stopSignList, stopSignBoxList);

               watch.Stop(); //stop the timer
               foreach (Rectangle rect in stopSignBoxList)
               {
                  image.Draw(rect, new Bgr(0,0,255), 2);
               }
               CGSize frameSize = FrameSize;
               using (Image<Bgr, byte> resized = image.Resize( (int)frameSize.Width, (int)frameSize.Height, Emgu.CV.CvEnum.INTER.CV_INTER_CUBIC, true))
               {
                  MessageText = String.Format("Detection time: {0} milli-seconds", watch.Elapsed.TotalMilliseconds);
                  SetImage(resized);
               }

            }
         };

      }
   }
}

