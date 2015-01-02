//----------------------------------------------------------------------------
//  Copyright (C) 2004-2013 by EMGU. All rights reserved.       
//----------------------------------------------------------------------------
using System;
using System.Collections.Generic;
using CoreGraphics;
using System.Linq;
using Emgu.CV;
using Emgu.CV.Structure;
using MonoTouch.Dialog;
using Foundation;
using UIKit;
using PlanarSubdivisionExample;

namespace Emgu.CV.Example.MonoTouch
{
    public class PlanarSubdivisionDialogViewController : DialogViewController
    {
        public PlanarSubdivisionDialogViewController()
         : base(new RootElement(""), true)
        {
        }

      public override void ViewDidLoad()
      {
         base.ViewDidLoad();
           RootElement root = Root;
         root.UnevenRows = true;
            UIImageView imageView = new UIImageView(View.Frame);
            //StringElement messageElement = new StringElement("");
         Section imageSection = new Section() {imageView};
            root.Add(new Section()
                 { new StyledStringElement("Process", delegate {

            using (Image<Bgr, byte> resized = DrawSubdivision.Draw(Math.Min( (int)View.Frame.Width, (int)View.Frame.Height) , 20))
            //using (Image<Bgr, Byte> resized = result.Resize((int)View.Frame.Width, (int)View.Frame.Height, Emgu.CV.CvEnum.INTER.CV_INTER_NN, true))
            {
               imageView.Frame = new CGRect(CGPoint.Empty, resized.Size);
               imageView.Image = resized.ToUIImage();
            }
            //messageElement.Value = String.Format("Detection Time: {0} milliseconds.", processingTime);
            //messageElement.GetImmediateRootElement().Reload(messageElement, UITableViewRowAnimation.Automatic);

            imageView.SetNeedsDisplay();
               this.ReloadData();
            }
            )});
            //root.Add(new Section() {messageElement});

            root.Add(imageSection);
      }
    }
}

